// Test: blocks differing only in whitespace/formatting

void compact_style(){int a=1;int b=2;int c=3;for(int i=0;i<10;i++){a+=i;b+=i*2;c+=i*3;}printf("Results: %d %d %d\n",a,b,c);}

void spaced_style() {
    int a = 1;
    int b = 2;
    int c = 3;
    for (int i = 0; i < 10; i++) {
        a += i;
        b += i * 2;
        c += i * 3;
    }
    printf("Results: %d %d %d\n", a, b, c);
}
