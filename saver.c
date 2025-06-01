#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <result> <filename>\n", argv[0]);
        return 1;
    }

    const char *result = argv[1];
    const char *filename = argv[2];

    FILE *file = fopen(filename, "a");
    if (!file) {
        perror("fopen error");
        return 1;
    }

    fprintf(file, "%s", result);
    fclose(file);

    return 0;
}

