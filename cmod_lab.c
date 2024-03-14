#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Usage: %s -f <file_path> -m <mask>\n", argv[0]);
        exit(1);
    }

    char *file_path = NULL;
    int mask = 0;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-f") == 0) {
            file_path = argv[i + 1];
            i++;
        } else if (strcmp(argv[i], "-m") == 0) {
            mask = strtol(argv[i + 1], NULL, 8);
            i++;
        } else {
            printf("Unknown option: %s\n", argv[i]);
            exit(1);
        }
    }

    if (file_path == NULL) {
        printf("Error: file path not specified\n");
        exit(1);
    }

    int result = chmod(file_path, mask);
    if (result == 0) {
        printf("Successfully changed permissions of '%s' to '%03o'\n", file_path, mask);
    } else {
        perror("Error changing permissions");
        exit(1);
    }

    return 0;
}
