// Test: nested similar blocks - when parent matches, children should be skipped

void outer_function_v1() {
    int setup = 1;
    int config = 2;

    // This inner block is similar to inner in v2
    if (setup > 0) {
        int x = 10;
        int y = 20;
        int z = 30;
        printf("Processing: %d %d %d\n", x, y, z);
        for (int i = 0; i < 10; i++) {
            printf("Loop iteration %d\n", i);
            x += i;
            y += i * 2;
            z += i * 3;
        }
        printf("Final: %d %d %d\n", x, y, z);
    }

    int cleanup = 3;
    printf("Done: %d\n", cleanup);
}

void outer_function_v2() {
    int setup = 1;
    int config = 2;

    // This inner block is similar to inner in v1
    if (setup > 0) {
        int x = 10;
        int y = 20;
        int z = 30;
        printf("Processing: %d %d %d\n", x, y, z);
        for (int i = 0; i < 10; i++) {
            printf("Loop iteration %d\n", i);
            x += i;
            y += i * 2;
            z += i * 3;
        }
        printf("Result: %d %d %d\n", x, y, z);
    }

    int cleanup = 3;
    printf("Done: %d\n", cleanup);
}
