// Test: blocks where quick_ratio might pass but full ratio fails
// quick_ratio uses length heuristics, full ratio does actual comparison

void function_aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa() {
    // Lots of 'a' characters to inflate quick_ratio
    int aaaa = 1;
    int aaab = 2;
    int aaac = 3;
    int aaad = 4;
    int aaae = 5;
    printf("aaaa: %d\n", aaaa);
    printf("aaab: %d\n", aaab);
    printf("aaac: %d\n", aaac);
    printf("aaad: %d\n", aaad);
    printf("aaae: %d\n", aaae);
}

void function_bbbbbbbbbbbbbbbbbbbbbbbbbbbbbb() {
    // Lots of 'b' characters - same structure but different content
    int bbbb = 1;
    int bbbc = 2;
    int bbbd = 3;
    int bbbe = 4;
    int bbbf = 5;
    printf("bbbb: %d\n", bbbb);
    printf("bbbc: %d\n", bbbc);
    printf("bbbd: %d\n", bbbd);
    printf("bbbe: %d\n", bbbe);
    printf("bbbf: %d\n", bbbf);
}
