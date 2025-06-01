#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <num1> <num2> <pipe_fd[1]>\n", argv[0]);
        return 1;
    }

    int x = atoi(argv[1]);
    int y = atoi(argv[2]);
    int pipefd = atoi(argv[3]);

    int res = x * y;

    char result_str[50];
    snprintf(result_str, sizeof(result_str), "%d\n", res);

    if (write(pipefd, result_str, strlen(result_str)) == -1) {
        perror("write error");
        return 1;
    }

    close(pipefd);

    return 0;
}

