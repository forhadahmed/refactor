// Test case: Escaped quotes in character literals cause parser issues
// The parser will incorrectly exit char literal state on escaped single quote

#include <stdio.h>

void test_escaped_char() {
    // Escaped single quote in char literal
    char quote = '\'';  // Parser exits char state on first ', thinks second ' starts new char

    // After the above line, parser may be in wrong state
    char brace = '{';   // This might be seen as real brace or char depending on state

    int x = 1;
}

void test_escaped_backslash() {
    // Escaped backslash followed by quote
    char backslash = '\\';  // Two backslashes
    char another = '\'';    // This should be fine but parser state may be off

    // More code
    if (1) {
        printf("inside if\n");
    }
}

void test_char_sequences() {
    // Various character literals that may confuse parser
    char a = '\"';  // Escaped double quote in single quotes - should be fine
    char b = '\\';  // Escaped backslash
    char c = '\'';  // Escaped single quote - PROBLEM

    // Check if we're still at correct indent
    for (int i = 0; i < 10; i++) {
        printf("%d\n", i);
    }
}
