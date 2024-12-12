#include<stdio.h>

void print_(int m) {
    if(m == 0) {
        puts("");
        return;
    }
    printf("* ");
    return print_(m - 1);
}

void triangle_pattern(int n, int m) {
    print_(m);
    if(n == m) {
        return;
    }
    return triangle_pattern(n, m + 1);
}

int main() {
    int n;
    scanf("%d", &n);
    triangle_pattern(n, 1);
    return 0;
}