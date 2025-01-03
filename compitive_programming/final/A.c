#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void print_array(int _array[][3], int arg_size) {
    for (int row = 0; row < arg_size; row++) {
        for (int col = 0; col < arg_size; col++) {
            printf("%2d ", _array[row][col]);
        }
        printf("\n");
    }
}


void Randomized_Squre(int _array[][3], int arg_size) {
    //read clock to obtain the seed 
    srand(time(NULL));
    for(int row = 0; row < arg_size; row++) {
        for(int col = 0; col < arg_size; col++) {
            //Random number generation (range from 1 to 99)
            _array[row][col] = rand() % 5 + 1;
        }
    }
}

int main() {
    int Matrix[3][3];
    Randomized_Squre(Matrix, 3);
    print_array(Matrix, 3);
    int A = 0;
    for(int i = 0; i < 3; i++) {
        int temp = 1;
        for(int k = 0; k < 3; k++ ) {
            temp *= Matrix[(i + k) % 3][k];
        }
        A += temp;
    }

    for(int i = 0; i < 3; i++) {
        int temp = 1;
        for(int k = 0; k < 3; k++ ) {
            temp *= Matrix[(i + k) % 3][(k * 2) % 3];
        }
        A -= temp;
    }

    printf("%d\n", A);
    return 0;
}