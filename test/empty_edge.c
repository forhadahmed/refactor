// Test: empty and minimal blocks

void empty_block() {}

void single_statement() { int x = 1; }

void only_comment() {
    // just a comment
}

void nested_empty() {
    if (1) {}
    if (2) {}
    if (3) {}
}

void real_content_after_empties() {
    int accumulator = 0;
    for (int i = 0; i < 100; i++) {
        accumulator += i;
        if (accumulator > 500) {
            printf("Hit limit at %d\n", i);
            break;
        }
    }
    printf("Final: %d\n", accumulator);
}

void similar_real_content() {
    int accumulator = 0;
    for (int i = 0; i < 100; i++) {
        accumulator += i;
        if (accumulator > 500) {
            printf("Hit limit at %d\n", i);
            break;
        }
    }
    printf("Result: %d\n", accumulator);
}
