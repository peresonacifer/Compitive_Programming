#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//the fuction is to randomizing a N * N matrix(the domain of number is 1 to 99)
void Randomize_matrix(int** matrix, int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            matrix[i][j] = rand() % 99 + 1;
        }
    }
}

//the fuction is to print a N * N matrix
void print_matrix(int** matrix, int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            printf("%2d ", matrix[i][j]);
        }
        puts("");
    }
    puts("");
}
//the fuction is to find duplicated value
void find_Duplicated_value(int ar[], int length) {
    //create a 1D array from 0 to 99
    int count_array[100] = {0};
    for(int i = 0; i < length; i++) {
        //count every element 
        count_array[ar[i]]++;
    }
    printf("Duplicated value(s):\n");
    int duplicated_Num = 0;
    //print duplicated value(s)
    for(int i = 0; i < length; i++) {
        if(count_array[ar[i]] > 1) {
            printf("%d ", ar[i]);
            //avoid printing repeatedly
            count_array[ar[i]] = 0; 
            duplicated_Num++;
        }
    }
    //if not, print None
    if(!duplicated_Num) printf("None");
    puts("");
}

// the fuciotn is flatten N * N array to 1D array and find the duplicated value
void Flatten_matrix_and_find_Duplicated_value(int** matrix, int size) {
    int length = size * size;
    int flatten_matrix[length];
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            //flattening them form every 0 row to n - 1 row
            flatten_matrix[i * size + j] = matrix[i][j];
        }
    }
    
    printf("\nFlattened matrix:\n");
    for(int i = 0; i < length; i++) printf("%d ", flatten_matrix[i]);
    puts("\n");
    find_Duplicated_value(flatten_matrix, length);

}

//the fuction is sorting algorithm
void bubble_sort(int ar[], int length) {
    for(int i = length - 1; i > 0; i--) {
        for(int j = 0; j < i; j++) {
            if(ar[j] > ar[j + 1]) {
                int temp;
                temp = ar[j];
                ar[j] = ar[j + 1];
                ar[j + 1] = temp;
            }
        }
    }
}

//the fuction is to find largest value after sorting them to strictly accending 1D array
int find_largest(int ar[], int length) {
    bubble_sort(ar, length);
    return ar[length - 1];
}

//the fuction is compress a N * N matrix
void Compressing_Matrix(int** matrix, int size) {
    //the result
    int compressed_matrix[2][2];
    //this is to find largest
    int temp_array[(size - 1) * (size - 1)];

    //the following 4 starting postions step by step
    for(int start_row = 0; start_row < 2; start_row++) {
        for(int start_col = 0; start_col < 2; start_col++) {
            int idx = 0; // set index = 0
            // from the starting positon, recording N - 1 * N - 1 elements
            for(int i = start_row; i < size - (1 - start_row); i++) {
                for(int j = start_col; j < size - (1 -start_col); j++) {
                    //after record a element, idx++
                    temp_array[idx++] = matrix[i][j];
                }
            }
            idx = 0; //reset idx
            //storing the final result
            compressed_matrix[start_row][start_col] = find_largest(temp_array, (size - 1) * (size - 1));
        }
    }
    //print the final result
    printf("Compressed matrix:\n");
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            printf("%2d ", compressed_matrix[i][j]);
        }
        puts("");
    }
}

int main() {
    srand(time(NULL));
    int Isize;
    
    printf("Enter the dimension of the metrix(range from 3 to 10): ");
    scanf("%d", &Isize);
    while(Isize < 3 || Isize > 10) {
        printf("Invalid dimension!!!(please enter 3 ~ 10)\n");
        scanf("%d", &Isize);
    }
    //allocate memory to N * N matrix 
    int** Matrix = (int**)malloc(Isize * sizeof(int*));
    if (!Matrix) {
        perror("Memory allocation failed");
        exit(1); 
    }
    for(int i = 0; i < Isize; i++) {
        Matrix[i] = (int*)malloc(Isize * sizeof(int));
        if (!Matrix[i]) {
            perror("Memory allocation failed");
            exit(1);
        }
    }
    //randoming them and print
    Randomize_matrix(Matrix, Isize);
    printf("Generated %d x %d matrix:\n", Isize, Isize);
    print_matrix(Matrix, Isize);

    //selecting the menu
    int Iopt = -1;
    while (Iopt != 3) {
        printf("Menu:\n1. Flatten matrix\n2. Compress matrix\n3. Exit\nEnter your option: ");
        scanf("%d", &Iopt);

        switch (Iopt) {
        case 1:
            Flatten_matrix_and_find_Duplicated_value(Matrix, Isize);
            puts("");
            break;
        case 2:
            puts("\nOringinal matrix:");
            print_matrix(Matrix, Isize);
            Compressing_Matrix(Matrix, Isize);
            puts("");
            break;
        case 3:
            puts("Program End!\n");
            break;

        default:
            printf("Invalid option!!!(please input again(1 ~ 3))\n");
            break;
        }
    }
    //free memory 
    for(int i = 0; i < Isize; i++) {
        free(Matrix[i]);
    }
    free(Matrix);

    return 0;
}