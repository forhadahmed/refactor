// File with similar functions for testing

void process_data_v1(int *data, int len) {
    int sum = 0;
    for (int i = 0; i < len; i++) {
        sum += data[i];
        if (data[i] > 100) {
            printf("Large value: %d\n", data[i]);
        }
    }
    printf("Sum: %d\n", sum);
    return;
}

void process_data_v2(int *data, int len) {
    int sum = 0;
    for (int i = 0; i < len; i++) {
        sum += data[i];
        if (data[i] > 200) {
            printf("Large value: %d\n", data[i]);
        }
    }
    printf("Total: %d\n", sum);
    return;
}
