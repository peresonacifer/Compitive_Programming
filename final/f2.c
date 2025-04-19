#include<stdio.h>
#include<stdlib.h>
#include<time.h>


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

void sort_2d_array(int** matrix, int rows, int columns) {
    int length = rows * columns;
    int temparray[length];
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            temparray[i * columns + j] = matrix[i][j];
        }
    }

    bubble_sort(temparray, length);

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            matrix[i][j] = temparray[i * columns + j];
        }
    }
}

void binary_search(int ar[], int left, int right, int num) {
    if(left <= right) {
        int mid = (left + right) / 2;
        if(ar[mid] == num) {
            printf("%d is in the matrix\n", num);
            return;
        }
        else if(ar[mid] > num) {
            binary_search(ar, left, mid - 1, num);
        }
        else {
            binary_search(ar, mid + 1, right, num);
        }
     }
    else {
        printf("%d is not in the matrix\n", num);
        return;
    }
} 

void find_a_number(int** matrix, int rows, int columns) {
    sort_2d_array(matrix, rows, columns);
    int num;
    printf("what is number you want to find: ");
    scanf("%d", &num);
    int temparray[rows * columns];
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            temparray[i * columns + j] = matrix[i][j];
        }
    }
    binary_search(temparray, 0, rows * columns - 1, num);
}

void find_mean(int** matrix, int rows, int columns) {
    int sum = 0;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            sum += matrix[i][j];
        }
    }
    printf("the mean of the randomized metrix is: %.2f\n", (float)sum / (rows * columns));

}

void print_matrix_in_spiral(int** matrix, int rows, int columns) {
    int left = 0, right = columns - 1, top = 0, bottom = rows - 1;
    while(left < right || top < bottom) {

        for(int i = left; i < right; i++) {
            printf("%d ", matrix[top][i]);
        }

        for(int i = top; i < bottom; i++) {
            printf("%d ", matrix[i][right]);
        }

        for(int i = right; i > left; i--) {
            printf("%d ", matrix[bottom][i]);
        }

        for(int i = bottom; i > top; i--) {
            printf("%d ", matrix[i][left]);
        }
        left++;
        top++;
        right--;
        bottom--;
    }
    if(left == right && top == bottom) printf("%d ", matrix[left][right]);
    puts("");
}

char** create_triangle_Matrix(int size) {
    char** Matrix = (char**)malloc(size * sizeof(char*));
    if(!Matrix) {
        perror("Memory allocation failed");
        exit(1);         
    }
    for(int i = 0; i < size; i++) {
        Matrix[i] = (char*)malloc(size * sizeof(char));
        if(!Matrix[i]) {
            perror("Memory allocation failed");
            exit(1);         
        }
    }
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < i + 1; j++) {
            Matrix[i][j] = '*';
        }
        for(int j = i + 1; j < size; j++) {
            Matrix[i][j] = ' ';
        }
    }

    return Matrix;
}

int** create_Ramdomized_Matrix(int rows, int columns) {
    int** Matrix = (int**)malloc(rows * sizeof(int*));
    if(!Matrix) {
        perror("Memory allocation failed");
        exit(1);         
    }
    for(int i = 0; i < rows; i++) {
        Matrix[i] = (int*)malloc(columns * sizeof(int));
        if(!Matrix[i]) {
            perror("Memory allocation failed");
            exit(1);         
        }
    }

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            Matrix[i][j] = rand() % 90 + 10;
        }
    }
    return Matrix;
}

void print_triangle_from_matrix(char** matrix, int size) {
    printf("---Current triangle---\n");
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            printf("%c ", matrix[i][j]);
        }
        puts("");
    }
}

void print_normal_matrix(int** matrix, int rows, int columns) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            printf("%d ", matrix[i][j]);
        }
        puts("");
    }
}

char** rotate_triangle_from_matrix(char** matrix, int size, int is_specified) {
    int whichone = 1;
    if(is_specified) {
        printf("1. 90\n2. 180\n3. 270\n");
        scanf("%d", &whichone);
        while(whichone < 1 || whichone > 3) {
            printf("Invalid input\n");
            printf("1. 90\n2. 180\n3. 270\n");
            scanf("%d", &whichone);
        }
    }
    char** rotated_matrix = create_triangle_Matrix(size); 
    if(whichone == 1) {
        for(int i = 0; i < size; i++) {     
            for(int j = 0; j < size; j++) { 
                rotated_matrix[i][j] = matrix[size - 1 - j][i];
            }
        }
    }
    else if(whichone == 2) {
        for(int i = 0; i < size; i++) {     
            for(int j = 0; j < size; j++) { 
                rotated_matrix[i][j] = matrix[size - 1 - i][size - 1 - j];
            }
        }
    }
    else {
        for(int i = 0; i < size; i++) {     
            for(int j = 0; j < size; j++) { 
                rotated_matrix[size - 1 - j][i] = matrix[i][j];
            }
        }
    }

    return rotated_matrix;
}

void print_diamond_pattern(int cur_n, int space_length, int star_length, int n) {
    if(cur_n > 2 * n) return;
    if(space_length > 0) {
        printf(" ");
        print_diamond_pattern(cur_n, space_length - 1, star_length, n);
    }
    else if(star_length > 0) {
        printf("*");
        print_diamond_pattern(cur_n, space_length, star_length - 1, n);
    }
    else {
        puts("");
        cur_n++;
        if(cur_n <= n) print_diamond_pattern(cur_n, n - cur_n, cur_n * 2 - 1, n);
        else print_diamond_pattern(cur_n, (cur_n % (n + 1)), (n - (cur_n % (n + 1))) * 2 - 1, n);
    }
}

void call_print_diamond_pattern() {
    int n;
    printf("Please input size: ");
    scanf("%d", &n);
    print_diamond_pattern(1, n - 1, 1, n);
}

int main() {
    srand(time(NULL));
    int Iopt, opt2;
    
    while(Iopt != 4) {
        int size, rows, columns;
        char** Matrix;
        int** randomize_Matrix;
        printf("Select Option\n1. rotate triangle.\n2. diamond pattern\n3. randomized matrix\n4. Exit program.\n");
        scanf("%d", &Iopt);
        switch (Iopt) {
            case 1:
                printf("Define size: ");
                scanf("%d", &size);
                Matrix = create_triangle_Matrix(size);
                while(opt2 != 5) {
                    printf("Select Option\n1. Define size\n2. Print triangle\n3. Rotate 90\n4. Specify rotation angle\n5. go back\n");
                    scanf("%d", &opt2);
                    switch (opt2) {
                        case 1:
                            printf("Define size: ");
                            scanf("%d", &size);
                            Matrix = create_triangle_Matrix(size);
                            break;
                        case 2:
                            print_triangle_from_matrix(Matrix, size);
                            break;
                        case 3:
                            Matrix = rotate_triangle_from_matrix(Matrix, size, 0);
                            print_triangle_from_matrix(Matrix, size);
                            break;
                        case 4:
                            Matrix = rotate_triangle_from_matrix(Matrix, size, 1);
                            print_triangle_from_matrix(Matrix, size);
                            break;
                        case 5:
                            break;
                        default:
                            printf("NA\n");
                            break;
                    }
                }
                opt2 = 0;
                break;
            case 2:
                call_print_diamond_pattern();
                break;
            case 3:
                printf("Please input rows and colums: ");
                scanf("%d %d", &rows, &columns);
                randomize_Matrix = create_Ramdomized_Matrix(rows, columns);
                printf("This is your matrix generated by random numbers: \n");
                print_normal_matrix(randomize_Matrix, rows, columns);
                while(opt2 != 6) {
                    printf("Select option\n1. find mean\n2. sort them\n3. find a number\n4. spiral\n5. find median\n6. go back\n");
                    scanf("%d", &opt2);
                    switch (opt2) {
                        case 1:
                            find_mean(randomize_Matrix, rows, columns);
                            break;
                        case 2:
                            sort_2d_array(randomize_Matrix, rows, columns);
                            printf("Matrix after sorting:\n");
                            print_normal_matrix(randomize_Matrix, rows, columns);
                            break;

                        case 3:
                            find_a_number(randomize_Matrix, rows, columns);
                            break;

                        case 4:
                            print_matrix_in_spiral(randomize_Matrix, rows, columns);
                            break;
                        case 5:
                            // find_median(randomize_Matrix, rows, columns);
                            break;
                        case 6:
                            break;
                        default:
                            break;
                    }
                }
                opt2 = 0;
                break;
            case 4:
                printf("Program End\n");
                break;
            default:
                break;
        }
    } 
}

// void spiralPrint(int rows, int cols, int matrix[MAX_ROWS][MAX_COLS]) {
//     int top = 0, bottom = rows - 1;
//     int left = 0, right = cols - 1;

//     while (top <= bottom && left <= right) {
//         // Print top row
//         for (int i = left; i <= right; i++) {
//             printf("%d ", matrix[top][i]);
//         }
//         top++;

//         // Print right column
//         for (int i = top; i <= bottom; i++) {
//             printf("%d ", matrix[i][right]);
//         }
//         right--;

//         // Print bottom row, if any rows are left
//         if (top <= bottom) {
//             for (int i = right; i >= left; i--) {
//                 printf("%d ", matrix[bottom][i]);
//             }
//             bottom--;
//         }

//         // Print left column, if any columns are left
//         if (left <= right) {
//             for (int i = bottom; i >= top; i--) {
//                 printf("%d ", matrix[i][left]);
//             }
//             left++;
//         }
//     }
//     printf("\n");
// }

