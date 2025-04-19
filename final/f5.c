#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int** matrix = (int**)malloc(n * sizeof(int*));
    if(!matrix) {
        perror("Memory allocation failed");
        exit(1);
    }

    for(int i = 0; i < n; i++) {
        matrix[i] = (int*)malloc(n * 2 * sizeof(int));
        if (!matrix[i]) {
            perror("Memory allocation failed");
            exit(1);
        }
    }
    int num = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            matrix[i][j] = -1;
        }
        for(int j = i; j < n; j++) {
            matrix[i][j] = ++num;
        }
    }

    for(int i = n - 1; i > -1; i--) {
        for(int j = n; j < n * 2 - i; j++) {
            matrix[i][j] = ++num;
        }
        for(int j = n * 2 - i; j < n * 2; j++) {
            matrix[i][j] = -1;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n * 2; j++) {
            if(matrix[i][j] == -1) printf(" ");
            else if(j + 1 == n * 2 || matrix[i][j + 1] == -1) printf("%d", matrix[i][j]);
            else printf("%d*", matrix[i][j]);
        }
        puts("");
    }
    
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}