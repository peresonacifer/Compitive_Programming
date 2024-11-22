#include<stdio.h>

int main() {
    /*
    123456
    *   *
     * *
      *
     * *  
    *   *  
    
    */
    int n;
    scanf("%d", &n);
    int left = 1, right = 2 * n - 1;
    for(int i = 1; i <= 2 * n - 1; i++) {
        for(int j = 1; j <= 2 * n - 1; j++) {
            if(j == left || j == right) {
                printf("*");
            }
            else{
                printf(" ");
            }
        }
        puts("");
        left++;
        right--;
    }
    /*
    1234567
      *
     * *
    *****
    *******
    */
    left = n, right = n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= 2 * n - 1; j++) {
            if(i != n) {
                if(j == left || j == right) {
                    printf("*");
                }
                else {
                    printf(" ");
                }
            }
            else {
                printf("*");
            }
        }
        puts("");
        left--;
        right++;
    }
    return 0;
}