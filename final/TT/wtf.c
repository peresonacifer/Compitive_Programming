#include <stdio.h>

void print_with_array(int n) {
    char myarray[n][2 * n - 1];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i + 1; j++) {
            myarray[i][j] = j + '1';
            myarray[i][2 * n - 2 - j] = j + '1';
        }
        
        for(int j = i + 1; j < 2 * n - 1 - (i + 1); j++) {
            myarray[i][j] = ' ';
        }
        // for(int j = i + 1; j > 0; j--) {
        //     if(j != n) {
        //         myarray[i][2 * n - 1 - j] = j + '0';
        //     }
        // }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 2 * n - 1; j++){
            printf("%c", myarray[i][j]);
        }
        puts("");
    }   
}

int main() {
    int n;
    scanf("%d", &n);
    print_with_array(n);
    return 0;
}
