#include <stdio.h>
#include <stdlib.h>

//the function is work for create matrix
int** createMatrix(int rows, int columns) {
    //allocate memory for 2D array
    int** Matrix = (int**)malloc(rows * sizeof(int*));
    if (!Matrix) {
        perror("Memory allocation failed");
        exit(1); 
    }
    for(int i = 0; i < rows; i++) {
        Matrix[i] = (int*)malloc(columns * sizeof(int));
        if (!Matrix[i]) {
            perror("Memory allocation failed");
            exit(1);
        }
    }
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            scanf("%d", &Matrix[i][j]);
        }
    }
    return Matrix;
}

//the fuction is work for transposing a matrix
void Transpose_a_Matrix(int rows, int columns, int** Matrix) {
    //print every row at fixed a column
    for(int i = 0; i < columns; i++) {
        for(int j = 0; j < rows; j++) {
            printf("%d ", Matrix[j][i]);
        }
        puts("");
    }
}

//the funtion is work for performing conformity check and if they can be multiplied multiplying them.
void Multiply_Matrices(int** MatrixA, int** MatrixB, int MatrixA_rows, int MatrixA_columns, int MatrixB_rows, int MatrixB_columns) {
    //conformity check
    if(MatrixA_columns != MatrixB_rows) {
        puts("They can not be multiplied.");
        return;
    }
    else {
        //from 0 to MatrixA_rows - 1
        for(int i = 0; i < MatrixA_rows; i++) {
            //from 0 to MatrixB_colums - 1
            for(int j = 0; j < MatrixB_columns; j++) {
                //Inationizing ans = 0
                int IAns = 0;
                //MatrixA_column multiply MatrixB_row
                for(int k = 0; k < MatrixA_columns; k++) {
                    IAns += MatrixA[i][k] * MatrixB[k][j];
                }
                printf("%d ", IAns);
            }
            puts("");
        }
    }
}

int main() {
    int MatrixA_rows, MatrixB_rows;
    int MatrixA_columns, MatrixB_columns;
    
    //prompt user to input
    printf("Enter dimensions of Matrix A(rows and columns): ");
    scanf("%d %d", &MatrixA_rows, &MatrixA_columns);

    //check the dimensions whether is valid or not(should be positive)
    while(MatrixA_rows <= 0 || MatrixA_columns <= 0) {
        if(MatrixA_rows <= 0) {
            printf("dimensions of Matrix A rows must be positive\nEnter your rows again: ");
            scanf("%d", &MatrixA_rows);
        }
        if(MatrixA_columns <= 0) {
            printf("dimensions of Matrix A columns must be positive\nEnter your columns again: ");
            scanf("%d", &MatrixA_columns);
        }      
    }
    puts("Matrix A:");
    //create MatrixA
    int** MatrixA = createMatrix(MatrixA_rows, MatrixA_columns);

    //then do the same thing to MatrixB
    printf("Enter dimensions of Matrix B(rows and columns): ");
    scanf("%d %d", &MatrixB_rows, &MatrixB_columns);
    
    while(MatrixB_rows <= 0 || MatrixB_columns <= 0) {
        if(MatrixB_rows <= 0) {
            printf("dimensions of Matrix B rows must be positive\nEnter your rows again: ");
            scanf("%d", &MatrixB_rows);
        }
        if(MatrixB_columns <= 0) {
            printf("dimensions of Matrix B columns must be positive\nEnter your columns again: ");
            scanf("%d", &MatrixB_columns);
        }      
    }
    puts("Matrix B:");
    int** MatrixB = createMatrix(MatrixB_rows, MatrixB_columns);

    //set a menu
    int IOpt = 0;
    while(IOpt != 3) {
        //menu display
        printf("Select an operation:\n1. Transpose a Matrix\n2. Multiply Matrices\n3. Exit\n> ");
        scanf("%d", &IOpt);
        int select_Matrix = 0;
        //perfroming selected option
        switch (IOpt)
        {
        case 1:
            //transposing Matrix (A or B)
            printf("Select Matrix to Transpose(1 for A, 2 for B): ");
            scanf("%d", &select_Matrix);
            while(select_Matrix != 1 && select_Matrix != 2) {
                printf("Please enter just 1 or 2 (for A or B): ");
                scanf("%d", &select_Matrix);
            }
            //invalid selection check
            if(select_Matrix == 1) {
                Transpose_a_Matrix(MatrixA_rows, MatrixA_columns, MatrixA);
            } else {
                Transpose_a_Matrix(MatrixB_rows, MatrixB_columns, MatrixB);
            }
            puts(""); 
            break;
        
        case 2:
            //multiplying two matrices after checking the MatrixA_columns equal to MatrixB_rows
            puts("Result of Matrix A x Matrix B:");
            Multiply_Matrices(MatrixA, MatrixB, MatrixA_rows, MatrixA_columns, MatrixB_rows, MatrixB_columns);
            puts("");
            break;

        case 3:
            //program end
            puts("Program exited.\n");
            break;

        //invalid menu selection
        default:
            puts("Invalid option!!! (please select an option below)");
            continue;
        }
    }
    //free memory
    for(int i = 0; i < MatrixA_rows; i++) {
        free(MatrixA[i]);
    }
    free(MatrixA);

    for(int i = 0; i < MatrixB_rows; i++) {
        free(MatrixB[i]);
    }
    free(MatrixB);

    return 0;
}
