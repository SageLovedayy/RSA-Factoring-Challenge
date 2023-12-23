#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

void factorize_number(uint64_t number);

void factorize_file(const char *file_path);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *file_path = argv[1];
    factorize_file(file_path);

    return 0;
}

void factorize_number(uint64_t number) {
    if (number <= 1) {
        printf("Invalid input: %" PRIu64 " (must be a natural number greater than 1)\n", number);
        return;
    }

    printf("%" PRIu64 "=", number);

    // Find the factors
    for (uint64_t i = 2; i * i <= number; i++) {
        while (number % i == 0) {
            printf("%" PRIu64, i);

            number /= i;

            if (number > 1) {
                printf("*");
            }
        }
    }

    // Output the remaining factor
    if (number > 1) {
        printf("%" PRIu64, number);
    }

    printf("\n");
}

void factorize_file(const char *file_path) {
    FILE *file = fopen(file_path, "r");

    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[50]; // Adjust the buffer size as needed
    while (fgets(line, sizeof(line), file) != NULL) {
        uint64_t number = strtoull(line, NULL, 10);
        factorize_number(number);
    }

    fclose(file);
}

