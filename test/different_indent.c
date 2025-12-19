// Test: similar code ONLY at different indent levels
// The outer functions are completely different
// Only the inner blocks (at different indents) are similar

void function_alpha() {
    // Unique content for alpha
    int alpha_setup = 111;
    char *alpha_name = "alpha";
    printf("Alpha: %s = %d\n", alpha_name, alpha_setup);

    // Similar block at indent level 1
    int shared_counter = 0;
    for (int idx = 0; idx < 50; idx++) {
        shared_counter += idx * 2;
        if (shared_counter > 200) {
            printf("Threshold hit at %d\n", idx);
            break;
        }
    }
    printf("Result: %d\n", shared_counter);
}

void function_beta() {
    // Completely different content for beta
    double beta_value = 3.14159;
    int beta_count = 999;
    printf("Beta: %f x %d\n", beta_value, beta_count);

    if (beta_count > 0) {
        // Similar block but at indent level 2
        int shared_counter = 0;
        for (int idx = 0; idx < 50; idx++) {
            shared_counter += idx * 2;
            if (shared_counter > 200) {
                printf("Threshold hit at %d\n", idx);
                break;
            }
        }
        printf("Result: %d\n", shared_counter);
    }
}
