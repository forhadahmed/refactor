// Test: blocks at exact size boundaries
// With --min-block-size=200, block1 should be filtered, block2 should pass

void block_under_limit() {
    // This block is exactly 199 characters of code content
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    int e = 5;
    int f = 6;
    int g = 7;
    int h = 8;
    printf("x");
}

void block_at_limit_one() {
    // This block should be right around 200+ characters
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    int e = 5;
    int f = 6;
    int g = 7;
    int h = 8;
    printf("xy");
}

void block_at_limit_two() {
    // This block should be right around 200+ characters
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    int e = 5;
    int f = 6;
    int g = 7;
    int h = 8;
    printf("xz");
}
