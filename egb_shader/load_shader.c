#include <stdio.h>
#include <stdlib.h>
#include "load_shader.h"

int load_shader(char* filename)
{
    char* buffer;
    unsigned long length;
    FILE* f = fopen(filename, "rb");

    if (f) {
        fseek(f, 0, SEEK_END);
        length = ftell(f);
        fseek(f, 0, SEEK_SET);
        buffer = malloc(length + 1);
        if (buffer) {
            fread(buffer, 1, length, f);
        }
        buffer[length] = '\0'; // Add string terminator
    } else {
        fprintf(stderr, "Err: Could not load shader file at %s\n", filename);
        return 1;
    }

    return 0;
}
