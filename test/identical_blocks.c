// Test: 100% identical blocks (degenerate case)

void identical_function_copy1() {
    int accumulator = 0;
    for (int i = 0; i < 100; i++) {
        accumulator += i * i;
        if (accumulator > 1000) {
            printf("Threshold reached at %d\n", i);
            break;
        }
    }
    printf("Final accumulator: %d\n", accumulator);
    return;
}

void identical_function_copy2() {
    int accumulator = 0;
    for (int i = 0; i < 100; i++) {
        accumulator += i * i;
        if (accumulator > 1000) {
            printf("Threshold reached at %d\n", i);
            break;
        }
    }
    printf("Final accumulator: %d\n", accumulator);
    return;
}
