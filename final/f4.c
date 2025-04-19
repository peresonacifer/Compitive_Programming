#include<stdio.h>

void print_digit(int n) {
    if(n < 10) {
        printf("%d ", n);
        return;
    }
    print_digit(n / 10);
    printf("%d ", n % 10);
}


int main() {
    int n;
    scanf("%d", &n);
    print_digit(n);
    puts("");
    return 0;
}