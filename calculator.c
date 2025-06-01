#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

void perform_operation(const char *operation, const char *num1, const char *num2) {
    int pipefd[2];
    if (pipe(pipefd) < 0) {
        perror("pipe error");
        exit(1);
    }

    pid_t p = fork();
    if (p < 0) {
        perror("fork error");
        exit(1);
    }

    if (p == 0) { // Child process
        close(pipefd[0]); // Close read end

        char wr_end[10];
        snprintf(wr_end, sizeof(wr_end), "%d", pipefd[1]);

        // Execute the corresponding operation
        execl(operation, operation, num1, num2, wr_end, NULL);

        perror("execl error");
        exit(1);
    } else { // Parent process
        close(pipefd[1]); // Close write end

        char buff[100];
        ssize_t n = read(pipefd[0], buff, sizeof(buff) - 1);

        if (n > 0) {
            buff[n] = '\0'; // Null-terminate the result
            printf("Result: %s", buff);

            // Call saver to save the result
            pid_t saver_pid = fork();
            if (saver_pid == 0) { // Child process for saver
                execl("./saver", "./saver", buff, "results.txt", NULL);
                perror("saver execl error");
                exit(1);
            }
            wait(NULL); // Wait for saver to finish
        } else {
            printf("No data received\n");
        }

        close(pipefd[0]);
        wait(NULL); // Wait for the child process to finish
    }
}

int main() {
    while (1) {
        printf("\nCalculator\n");
        printf("1- addition\n");
        printf("2- subtraction\n");
        printf("3- multiplication\n");
        printf("4- division\n");
        printf("5- exit\n");
        printf("Choose an operation: ");

        int choice;
        scanf("%d", &choice);

        if (choice == 5) {
            printf("Exiting...\n");
            break;
        }

        char num1[10], num2[10];
        printf("Enter the first number: ");
        scanf("%9s", num1);
        printf("Enter the second number: ");
        scanf("%9s", num2);

        switch (choice) {
            case 1:
                perform_operation("./add", num1, num2);
                break;
            case 2:
                perform_operation("./sub", num1, num2);
                break;
            case 3:
                perform_operation("./mul", num1, num2);
                break;
            case 4:
                perform_operation("./div", num1, num2);
                break;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

