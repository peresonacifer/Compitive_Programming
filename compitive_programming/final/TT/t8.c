#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int a[n], b[n];
    int temp;
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        for(int j = i; j > 0; j--) {
            if(a[j] < a[j - 1]) {
                temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;    
            }
        }
    }

    for(int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
        for(int j = i; j > 0; j--) {
            if(b[j] < b[j - 1]) {
                temp = b[j];
                b[j] = b[j - 1];
                b[j - 1] = temp;    
            }
        }
    }

    int is_permutation = 1;
    for(int i = 0; i < n; i++) {
        if(a[i] != b[i]) {
            is_permutation = 0;
            break;
        }
    }
    if(is_permutation) {
        printf("yes\n");
    }
    else {
        printf("no\n");
    }
    
    return 0;
}