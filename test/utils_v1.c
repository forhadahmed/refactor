// Utility functions version 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validate_input(const char *input, int max_len) {
    if (input == NULL) {
        fprintf(stderr, "Error: input is NULL\n");
        return -1;
    }
    int len = strlen(input);
    if (len == 0) {
        fprintf(stderr, "Error: input is empty\n");
        return -1;
    }
    if (len > max_len) {
        fprintf(stderr, "Error: input too long (%d > %d)\n", len, max_len);
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

void process_buffer(char *buffer, int size, int flags) {
    if (buffer == NULL || size <= 0) {
        return;
    }
    for (int i = 0; i < size; i++) {
        if (flags & 0x01) {
            buffer[i] = buffer[i] ^ 0xFF;
        }
        if (flags & 0x02) {
            if (buffer[i] >= 'a' && buffer[i] <= 'z') {
                buffer[i] = buffer[i] - 32;
            }
        }
        if (flags & 0x04) {
            if (buffer[i] >= 'A' && buffer[i] <= 'Z') {
                buffer[i] = buffer[i] + 32;
            }
        }
    }
}

int find_pattern(const char *haystack, const char *needle) {
    if (haystack == NULL || needle == NULL) {
        return -1;
    }
    int hlen = strlen(haystack);
    int nlen = strlen(needle);
    if (nlen == 0 || nlen > hlen) {
        return -1;
    }
    for (int i = 0; i <= hlen - nlen; i++) {
        int match = 1;
        for (int j = 0; j < nlen; j++) {
            if (haystack[i + j] != needle[j]) {
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
