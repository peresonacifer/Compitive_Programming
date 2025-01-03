#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//This is work for printing array
void print_array(int** _array, int arg_size) {
    for (int row = 0; row < arg_size; row++) {
        for (int col = 0; col < arg_size; col++) {
            printf("%2d ", _array[row][col]);
        }
        printf("\n");
    }
}

//This is work for giving random value for Original_array
void Randomized_Squre(int** _array, int arg_size) {
    //read clock to obtain the seed 
    srand(time(NULL));
    for(int row = 0; row < arg_size; row++) {
        for(int col = 0; col < arg_size; col++) {
            //Random number generation (range from 1 to 99)
            _array[row][col] = rand() % 99 + 1;
        }
    }
}

/*  
Original_array[n - 1][0] ~ [0][0]         ---> Rotated_array[0][0] ~ Rotated_array[0][n - 1]       
...                         
Original_array[n - 1][n - 1] ~ [0][n - 1] ---> Rotated_array[n - 1][0] ~ Rotated_array[n - 1][n - 1]
where n means Size.
*/
void Square_Rotated_90_degree_R(int** _arrayO, int** _arrayR, int arg_size) {
    for(int row = 0; row < arg_size; row++) {
        for(int col = 0; col < arg_size; col++) {
            _arrayR[row][col] = _arrayO[arg_size - col - 1][row];            
        }
    }
}

void Sorted_array(int **array, int size) {
    int *temp = (int*)malloc(size * size * sizeof(int));
    int cur = 0;
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
           temp[cur++] = array[i][j];
        } 
    }
    for(int k = cur - 1; k > 0; k--) {
        for(int h = 0; h < k; h++) {
            if(temp[h] > temp[h + 1]) {
                int a = temp[h];
                temp[h] = temp[h + 1];
                temp[h + 1] = a;
            }
        }
    }
    cur = 0;
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
           array[i][j] = temp[cur++];
        } 
    }
}

int main() {
    int Size;
    //Prompt user what to do
    printf("Please enter the size of the square. (size between the 2 and 10)\n");
    scanf("%d", &Size);

    //To check size whether is valid
    while (Size < 2 || Size > 10) {
        printf("Invalid size. Please input again.\n");
        scanf("%d", &Size);    
    }
    
    //Allocate memory for the array of pointer. I declare oringinal one and Rotated one
    int** Original_array = (int**)malloc(Size * sizeof(int*));
    int** Rotated_array = (int**)malloc(Size * sizeof(int*));
    //check whether allocating memory is successful
    if (!Original_array || !Rotated_array) {
        perror("Memory allocation failed");
        return EXIT_FAILURE;
    }

    //Allocate memory for the array of integers for each pointer 
    for (int i = 0; i < Size; i++) {
        Original_array[i] = (int*)malloc(Size * sizeof(int));
        Rotated_array[i] = (int*)malloc(Size * sizeof(int));
        //check whether allocating memory is successful
        if (!Original_array[i] || !Rotated_array[i]) {
            perror("Memory allocation failed");
            return EXIT_FAILURE;
        }
    }

    //Initialize the array with zero
    for (int row = 0; row < Size; row++) {
        for (int col = 0; col < Size; col++) {
            Original_array[row][col] = 0;
            Rotated_array[row][col] = 0;
        }
    }
    //Print result of initialized, randomized, and 90 degree right rotated square
    puts("Initialized square:");
    print_array(Original_array, Size);
    Randomized_Squre(Original_array, Size);
    puts("Randomized square:");
    print_array(Original_array, Size);
    Square_Rotated_90_degree_R(Original_array, Rotated_array, Size);
    puts("Square rotated 90 degree:");
    print_array(Rotated_array, Size);
    puts("Sorted_array:");
    Sorted_array(Rotated_array, Size);
    print_array(Rotated_array, Size);
    puts("Program ends");

    // Free the allocated memory to avoid memory leaks
    for (int i = 0; i < Size; i++) {
        free(Original_array[i]);
        free(Rotated_array[i]);
    }
    free(Rotated_array);
    free(Original_array);

    return 0;
}