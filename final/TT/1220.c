#include <stdio.h>

void Inaltionize(int row, int col, int array[row][col]) {
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            array[i][j] = 0;
            printf("%d", array[i][j]);
        }
    }
}


int main() {
    int row = 10, col = 10;
    int array[row][col];
    // print_ar(row, col, array);
    Inaltionize(row, col, array);
    return 0;
}

// void print_ar(int row, int col, int ar[row][col]) {
//     printf("%d", ar[0][0]);
//     // for(int i = 0; i < row; i++) {
//     //     for(int j = 0; j < col; j++) {
//     //         printf("%d", ar[i][j]);
//     //     }
//     // }
// }