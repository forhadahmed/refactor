// Test case: Escaped quotes in strings cause parser to incorrectly exit string state
// The parser will think the brace after the escaped quote is real code

#include <stdio.h>

void correct_function() {
    // This function has one block - the function body
    int x = 1;
    int y = 2;
}

void broken_by_escaped_quote() {
    // The escaped quote below will cause parser to exit string state early
    // Parser will see the { inside the string as a real brace
    char *str = "this has an escaped quote \" and a fake block { inside } the string";

    // Parser now thinks we're at indent level 2 instead of 1
    int a = 10;
    int b = 20;
}

void another_escaped_quote_issue() {
    // Multiple escaped quotes
    char *json = "{\"name\": \"value\", \"nested\": {\"key\": \"data\"}}";

    // Parser is now completely confused about brace depth
    printf("This should be at indent 1\n");
}

// After the above functions, the parser's indent counter should be 0
// But due to the fake braces in strings, it will likely be wrong

void final_function() {
    int z = 100;
}
