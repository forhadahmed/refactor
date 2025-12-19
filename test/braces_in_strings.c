// Test: braces inside strings and comments should NOT create blocks

void function_with_string_braces() {
    // Comment with { braces } should not affect parsing
    char *json = "{ \"key\": \"value\" }";
    char *nested = "{ { { deeply { nested } } } }";

    /* Multi-line comment
       with { braces } inside
       { more { braces } }
       should be ignored */

    printf("Braces in string: %s\n", json);
    printf("Nested: %s\n", nested);

    // Real block follows
    if (1) {
        int x = 1;
        printf("Real block: %d\n", x);
    }
}

void another_function_with_string_braces() {
    // Comment with { braces } should not affect parsing
    char *json = "{ \"key\": \"value\" }";
    char *nested = "{ { { deeply { nested } } } }";

    /* Multi-line comment
       with { braces } inside
       { more { braces } }
       should be ignored */

    printf("Braces in string: %s\n", json);
    printf("Nested: %s\n", nested);

    // Real block follows
    if (1) {
        int y = 2;
        printf("Real block: %d\n", y);
    }
}
