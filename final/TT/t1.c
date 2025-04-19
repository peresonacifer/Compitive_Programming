#include<stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n;
    srand(time(NULL));

    for(int i = 0; i < 7; i++) {
        printf("%d \n", rand() % 49 + 1);
    }

    // scanf("%d", &n);
    // triangle_pattern(n, 1);
    return 0;
}