// Utility functions version 2 - similar to v1 with minor changes

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validate_user_input(const char *input, int max_length) {
    if (input == NULL) {
        fprintf(stderr, "Error: input is NULL\n");
        return -1;
    }
    int len = strlen(input);
    if (len == 0) {
        fprintf(stderr, "Error: input is empty\n");
        return -1;
    }
    if (len > max_length) {
        fprintf(stderr, "Error: input too long (%d > %d)\n", len, max_length);
        return -1;
    }
    for (int i = 0; i < len; i++) {
        if (input[i] < 32 || input[i] > 126) {
            fprintf(stderr, "Error: invalid character at position %d\n", i);
            return -1;
        }
    }
    return 0;
}

void transform_buffer(char *buffer, int size, int options) {
    if (buffer == NULL || size <= 0) {
        return;
    }
    for (int i = 0; i < size; i++) {
        if (options & 0x01) {
            buffer[i] = buffer[i] ^ 0xFF;
        }
        if (options & 0x02) {
            if (buffer[i] >= 'a' && buffer[i] <= 'z') {
                buffer[i] = buffer[i] - 32;
            }
        }
        if (options & 0x04) {
            if (buffer[i] >= 'A' && buffer[i] <= 'Z') {
                buffer[i] = buffer[i] + 32;
            }
        }
    }
}

int search_pattern(const char *text, const char *pattern) {
    if (text == NULL || pattern == NULL) {
        return -1;
    }
    int tlen = strlen(text);
    int plen = strlen(pattern);
    if (plen == 0 || plen > tlen) {
        return -1;
    }
    for (int i = 0; i <= tlen - plen; i++) {
        int match = 1;
        for (int j = 0; j < plen; j++) {
            if (text[i + j] != pattern[j]) {
                match = 0;
                break;
            }
        }
        if (match) {
            return i;
        }
    }
    return -1;
}
