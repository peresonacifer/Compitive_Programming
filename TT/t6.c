#include<stdio.h>

void print_even_indices(int a[], int n) {
    if(n < 0) {
        return;
    }
    if(!(n % 2)) {
        printf("%d ", a[n]);
    }
    print_even_indices(a, n - 1);
}

int main() {
    int n;
    scanf("%d", &n);
    int array[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    print_even_indices(array, n - 1);

    return 0;
}