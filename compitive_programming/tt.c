#include <stdio.h>

int main () {
    int n;
    for (int i = 0; i < 4; i++) {
        scanf("%d", &n);
        printf("%d\n", n);
    }

    while(scanf("%d", &n) && n != 0) {
        printf("%d\n", n);
    }
    
    return 0;
}