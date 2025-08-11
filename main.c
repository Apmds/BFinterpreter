#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#define SHIFT_RIGHT '>'
#define SHIFT_LEFT '<'
#define ADD '+'
#define SUB '-'
#define INPUT ','
#define OUTPUT '.'
#define LOOP_START '['
#define LOOP_END ']'

bool is_bf_char(char c) {
    return c == SHIFT_LEFT
        || c == SHIFT_RIGHT
        || c == ADD
        || c == SUB
        || c == INPUT
        || c == OUTPUT
        || c == LOOP_START
        || c == LOOP_END
    ;
}

bool is_valid_program(char* program) {
    char* c = program;
    int loop_nesting = 0;
    while (*c != '\0') {
        if (*c == LOOP_START) {
            loop_nesting++;
        }
        if (*c == LOOP_END) {
            loop_nesting--;
        }
        c++;
    }

    return loop_nesting == 0;
}

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        fprintf(stderr, "Must provide program!\n");
        return EXIT_FAILURE;
    }

    // Getting program contents
    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file!");
        return EXIT_FAILURE;
    }

    // Buffer with all of the program contents (all the uneedded characters are already removed from here)
    char* program = NULL;
    int prog_size = 0;

    char buf[100];
    while (fgets(buf, sizeof(buf), file) != NULL) {
        int buf_instruction_size = 0; // Size of buffer (considering only the needed characters)
        char* c = buf;
        while (*c != '\0') {
            if (is_bf_char(*c)) {
                buf_instruction_size++;
            }

            c++;
        }

        program = realloc(program, prog_size + buf_instruction_size + 1);
        program[prog_size + buf_instruction_size] = '\0';
        int idx = prog_size; // Index where the new data should be added
        prog_size += buf_instruction_size;

        // Read the buffer again to put the data in the program
        c = buf;
        while (*c != '\0') {
            if (is_bf_char(*c)) {
                program[idx++] = *c;
            }

            c++;
        }
    }
    printf("Program: %s\n", program);
    fclose(file);

    // Validating program
    if (!is_valid_program(program)) {
        fprintf(stderr, "Given program is invalid!\n");
        return EXIT_FAILURE;
    }

    // Data buffer
    char data[30000];


    int data_pointer = 0;
    
    free(program);
    return EXIT_SUCCESS;
}