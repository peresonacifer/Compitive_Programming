#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int fb(int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    return fb(n - 1) + fb(n - 2);
}

void sheet99() {
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            printf("%dx%d=%2d  ", i, j, i * j);
        }
        puts("");
    }
}

void findmax_in_2darray() {
    int n, m;
    scanf("%d %d", &n, &m);
    int matrix[n][m];
    int max = INT_MIN;
    int max_row = 0, max_col = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] > max) {
                max = matrix[i][j];
                max_row = i;
                max_col = j;
            }
        }
    }
    printf("The maximum is: %d\n", max);
    printf("And the row and column is %d and %d respectively\n", max_row, max_col);
}

void selection_sort() {
    int n;
    scanf("%d", &n);
    int ar[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &ar[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ar[j] < ar[i]) {
                int temp = ar[i];
                ar[i] = ar[j];
                ar[j] = temp;
            }
        }
    }
    printf("The result:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", ar[i]);
    }
    puts("");
}

int binary_sort(int ar[], int left, int right, int num) {
    if (left > right) return -1;
    int mid = (left + right) / 2;
    if (ar[mid] == num) return mid;
    else if (ar[mid] < num) return binary_sort(ar, mid + 1, right, num);
    else return binary_sort(ar, left, mid - 1, num);
}

void binary_sort_a_array() {
    int n;
    scanf("%d", &n);
    int ar[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &ar[i]);
    }
    int num;
    scanf("%d", &num);

    int result = binary_sort(ar, 0, n - 1, num);
    if (result != -1) {
        printf("The number is at index %d\n", result);
    } else {
        printf("The number is not in the array.\n");
    }
}

int main() {
    int iopt = 0;
    while (iopt != 6) {
        printf("Select the problem (1-5, 6 to exit): ");
        scanf("%d", &iopt);
        switch (iopt) {
            case 1:
                {
                    int n;
                    printf("Enter n for Fibonacci: ");
                    scanf("%d", &n);
                    printf("Fibonacci(%d) = %d\n", n, fb(n));
                    break;
                }
            case 2:
                sheet99();
                break;
            case 3:
                findmax_in_2darray();
                break;
            case 4:
                selection_sort();
                break;
            case 5:
                binary_sort_a_array();
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid option. Try again.\n");
        }
    }
    return 0;
}
