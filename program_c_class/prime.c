#include<stdio.h>

int main () {
    int n;
    scanf("%d", &n);
    int a[101] = {0}, b[101] = {0}, x = 0;
    for (int i = 2; i <= n; i++) {
        if(a[i] == 0) {
            printf("%d\n" ,i);
            b[x] = i;
            x++;
        }
        for (int j = 0; i * b[j] <= n; j++) {
            a[i * b[j]] = b[j];
            if (i % b[j] == 0) break;
        }
    }

    return 0;    
}