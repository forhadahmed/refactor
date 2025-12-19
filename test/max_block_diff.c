// Test: blocks that differ by exactly/around max-block-diff
// Default max-block-diff is 500 bytes
// If blocks differ by more than max-block-diff, comparison is skipped

void small_function() {
    int x = 1;
    int y = 2;
    printf("Small: %d %d\n", x, y);
}

void large_function_with_extra_content() {
    int x = 1;
    int y = 2;
    printf("Small: %d %d\n", x, y);

    // Extra content to push size difference over max-block-diff
    // This padding makes the function much larger
    int pad01 = 1; int pad02 = 2; int pad03 = 3; int pad04 = 4;
    int pad05 = 5; int pad06 = 6; int pad07 = 7; int pad08 = 8;
    int pad09 = 9; int pad10 = 10; int pad11 = 11; int pad12 = 12;
    int pad13 = 13; int pad14 = 14; int pad15 = 15; int pad16 = 16;
    int pad17 = 17; int pad18 = 18; int pad19 = 19; int pad20 = 20;
    int pad21 = 21; int pad22 = 22; int pad23 = 23; int pad24 = 24;
    int pad25 = 25; int pad26 = 26; int pad27 = 27; int pad28 = 28;
    int pad29 = 29; int pad30 = 30; int pad31 = 31; int pad32 = 32;
    printf("Padded: %d\n", pad01 + pad32);
}

void medium_function_within_diff() {
    int x = 1;
    int y = 2;
    printf("Small: %d %d\n", x, y);

    // Some extra but within max-block-diff
    int extra1 = 100;
    int extra2 = 200;
    printf("Extra: %d %d\n", extra1, extra2);
}
