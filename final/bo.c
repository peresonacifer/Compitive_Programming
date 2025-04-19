#include<stdio.h>

int main() {
    int n, ans = 0;
    scanf("%d", &n);
    ans += n;
    while(n >= 5) {
        n = n - 5 + 2;
        ans += 2;
    }
    printf("%d", ans);
    return 0;
}
// 8 2 2