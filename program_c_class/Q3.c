#include <stdio.h>

// int main (void) {
//     int n;
//     float ap = 0; //原來要初始化阿
//     scanf("%d", &n);
//     for (int i = 0; i < 4; i++ ) {
//         float x = 5.0;
//         for (int j = 0; j < i; j++) x /= 10;
//         ap += x;
//         if (ap * ap > n) {
//             while (ap * ap > n) ap -= x / 5;
//         } 
//         else {
//             while (ap * ap < n) ap += x / 5;
//         }
//         // printf("%f ", ap);
//     }
//     // puts("");
//     printf("%.3f", ap);
//     return 0;

// }

int main(void) {
    int n;
    float low, high, mid;
    
    scanf("%d", &n);

    low = 0;
    high = n;
    mid = (low + high) / 2;

    // 進行20次迭代，逐步逼近開根號
    for (int i = 0; i < 20; i++) {
        if (mid * mid > n) {
            high = mid;
        } else {
            low = mid;
        }
        mid = (low + high) / 2;
        // printf("%f ", mid);
    }

    printf("Approximate square root of %d is: %.6f\n", n, mid);
    return 0;
}
