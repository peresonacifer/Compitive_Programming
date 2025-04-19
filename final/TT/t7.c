#include <stdio.h>
// sum_N-1_nums = N-1_means * n - 1
// N_mean = N_num + sum_N-1_nums / N

float find_mean(int a[], int n) {
    if(n == 1) {
        return a[n - 1];
    }
    return (float)(a[n - 1] + find_mean(a, n - 1) * (n - 1)) / n;
}

int main() {
    int n;
    scanf("%d", &n);
    int ar[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &ar[i]);
    }
    printf("%.2f", find_mean(ar, n));
    return 0;
}