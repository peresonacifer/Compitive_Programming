#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>

void TRue_array_mode() {
    int n;
    scanf("%d", &n);
    int ar[n][n], ans[n][n];

    // Input the array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &ar[i][j]);
        }
    }

    // Initialize the answer array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans[i][j] = ar[i][j];
        }
    }

    // Perform the spiral rotation
    int t = n / 2;
    int start_pos = 0;
    int move = n - 1;

    while (t--) {
        int left = start_pos, top = start_pos, right = n - 1 - start_pos, bottom = n - 1 - start_pos;
        int temp = move;
        
        // Rotate top row
        for (int i = 0; i < move; i++) {
            ans[left + i][top] = ar[left + i + 1][top];
        }

        // Rotate right column
        for (int i = 0; i < move; i++) {
            ans[right][top + i] = ar[right][top + i + 1];
        }

        // Rotate bottom row
        for (int i = 0; i < move; i++) {
            ans[right - i][bottom] = ar[right - i - 1][bottom];
        }

        // Rotate left column
        for (int i = 0; i < move; i++) {
            ans[left][bottom - i] = ar[left][bottom - i - 1];
        }

        move -= 2;
        start_pos++;
    }

    // Output the rotated matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", ans[i][j]);
        }
        puts("");
    }
}
void array_mode() {
    int n;
    scanf("%d", &n);
    int ar[n][n], ans[n][n];
    for(int i = 0; i < n ; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &ar[i][j]);
        }
    }
    int t = n / 2;
    int start_pos = 0;
    int move = n - 1;
    while(t--) {
        int left = start_pos , top = start_pos, right = n - 1 - start_pos, bottom = n - 1 - start_pos;
        int temp = move;
        for(int i = 1; i <= move; i++) {
            ans[left + i][top] = ar[left + i - 1][top];
            if(i == move) {
                left = left + i;
            }
        }

        for(int i = 1; i <= move; i++) {
            ans[left][top + i] = ans[left][top + i - 1];
            if(i == move) {
                top = top + i;
            }
        }


        for(int i = 1; i <= move; i++) {
            ans[right - i][bottom] = ans[right - i + 1][bottom];
            if(i == move) {
                right = right - i;
            }
        }

        for(int i = 1; i <= move; i++) {
            ans[right][bottom - i] = ans[right][bottom - i + 1];
            if(i == move) {
                bottom = bottom - i;
            }            
        }
        move -= 2;

        if(t == 1 && n % 2) {

        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", ans[i][j]);
        }
        puts("");
    }
}

void diamond_pattern() {
    ;
}


void print_pattern(int n) {
    if(n == 0) {
        return;
    }
    printf("* ");
    print_pattern(n - 1);
}

void print_space(int n) {
    if(n == 0) {
        return;
    }
    printf("  ");
    print_space(n - 1);
}

void triangle_graphic(int n, int l) {
    if(l > n) {
        return;
    }

    print_space((n- (abs((n + 1) / 2 - l) * 2 + 1)) / 2);
    print_pattern(abs((n + 1) / 2 - l) * 2 + 1);
    puts("");
    triangle_graphic(n, l + 1);
}

void triangle_pattern() {
    int n;
    scanf("%d", &n);
    triangle_graphic(n, 1);
}

int main() {
    
    int iOpt;
    do {
        printf("Please choose which option you want to do:\n1: Square pattern\n2: Diamond pattern with stars \n3: Standardize three numbers\n4: End program\n");
        scanf("%d", &iOpt);
        while (1) {
            switch (iOpt)
            {
            case 1:
                triangle_pattern();
                puts("\n<back to top level menu>");
                break;
            case 2:
                diamond_pattern();
                puts("\n<back to top level menu>");
                break;
            case 3:
                array_mode();
                puts("\n<back to top level menu>");
                break;
            case 4:
                break;
            default:
                printf("Wrong option, please input again: ");
                scanf("%d", &iOpt);
                continue;
            }
            break;
        }
        
    }while(iOpt != 4);

    return 0;
}