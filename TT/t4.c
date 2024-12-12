#include <stdio.h>

void print_digits(int num, int ans_ar[10], int idx) {
    ans_ar[idx] = num % 10;
    if(num < 10) {
        for(int i = idx; i > -1; i--) {
            printf("%d ", ans_ar[i]);
        }
        puts("");
        return;
    }
    print_digits((num - (num % 10)) / 10, ans_ar, idx + 1);
}

void call_print_digits(int totalnums, int a[], int idx) {
    if(idx == totalnums) {
        return;
    }
    int ans[10] = {0};
    print_digits(a[idx], ans, 0);
    call_print_digits(totalnums, a, idx + 1);
}

int main() {
    int TotalNums;
    scanf("%d", &TotalNums);
    int array[TotalNums];
    for(int i = 0; i < TotalNums; i++) {
        scanf("%d", &array[i]);
    }
    call_print_digits(TotalNums, array, 0);

    return 0;
}