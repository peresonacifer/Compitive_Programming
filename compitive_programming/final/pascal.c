#include<stdio.h>

int pascal_thm(int n, int k) {
    if(n == 0 || k == 0 || n == k) return 1;
    return pascal_thm(n - 1, k) + pascal_thm(n - 1, k - 1);
}

void pascal_triangle(int cur_n, int space_length, int pattern_length, int n) {
    if(cur_n > n) return;
    else if(space_length > 0) {
        printf(" ");
        pascal_triangle(cur_n, space_length - 1, pattern_length, n);
    }
    else if(pattern_length > 0) {
        printf("%d ", pascal_thm(cur_n - 1, cur_n - pattern_length));
        pascal_triangle(cur_n, space_length, pattern_length - 1, n);
    }
    else {
        puts("");
        cur_n++;
        pascal_triangle(cur_n, n - cur_n, cur_n, n);
    }


}

int main() {
    int n;

    scanf("%d", &n);
    // printf("%d", pascal_thm(n , k));
    pascal_triangle(1, n - 1, 1, n);
    return 0;
}

