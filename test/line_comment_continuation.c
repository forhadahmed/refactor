// Test case: Line comments should NOT be continued with backslash
// But the parser treats // comments same as #define macros for continuation
// This causes real code after a comment with trailing \ to be hidden

#include <stdio.h>

void test_comment_continuation() {
    int before = 1;

    // This comment ends with a backslash \
    int hidden_code = 2;  // Parser thinks this is still a comment!

    // The variable above should exist but parser skips it
    int after = 3;

    // Another example with brace \
    if (1) {
        printf("This whole block is hidden from parser\n");
    }

    printf("Are we at right indent level?\n");
}

void test_multiple_continuations() {
    // Comment line 1 \
    // This looks like comment but parser sees it as continuation \
    int x = 1;  // This is real code but hidden!

    // Normal comment without backslash
    int y = 2;  // This should be visible

    if (x) {
        // nested comment \
        for (int i = 0; i < 10; i++) {
            printf("%d\n", i);  // All this hidden!
        }
    }
}

// The brace counting will be completely wrong after these functions
