#include<stdio.h>
#include<math.h>
#include<stdbool.h>

void print_pattern(int m, int n){
    int left = m, right = 2 * n - 1 - (m - 1);
    int Num = 1;
    for(int i = 1; i <= 2 * n - 1; i++) {
        if(i <= left || i >= right) {
            printf("%d", Num);
            if(i < left) Num++;
            if(i >= right) Num--;
        }
        else {
            printf(" ");
        }
    }
    puts("");
}

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

void symmetry_pattern(int n, int m) {
    print_pattern(m, n);
    if(n == m) {
        return;
    }

    return symmetry_pattern(n, m + 1); 
}

void Diamond_pattern_print_space(int n) {
    if(n == 0) {
        return;
    }
    printf("  ");
    Diamond_pattern_print_space(n - 1);
}

void Diamond_pattern_print_graphic(int t, int l, bool *accending, int *num) {
    if(t == 0) return;  
    if(l % 2) {
        if(t % 2) {
            printf("%d ", *num);
            if(*accending) {
                (*num)++;
            } else {
                (*num)--;
            }
        } else {
            printf("* ");
        }
    } else {
        if(t % 2) {
            printf("* ");
        } else {
            printf("%d ", *num);
            if(*accending) {
                (*num)++;
            } else {
                (*num)--;
            }
        }
    }
    if(*num == 9 && *accending == true) {
        *accending = false;
    }
    if(*num == 1 && *accending == false) {
        *accending = true;
    }
    Diamond_pattern_print_graphic(t - 1, l, accending, num);
}

void Diamond_pattern(int n, int l, bool accending, int *num) {
    if(l > n) {
        return;
    }
    Diamond_pattern_print_space(abs((n + 1) / 2 - l));
    int t = (l * 2 - 1 > n) ? (2 * ((n + 1) - l) - 1) : (l * 2 - 1);
    Diamond_pattern_print_graphic(t, l, &accending, num);
    puts("");
    Diamond_pattern(n, l + 1, accending, num);
}

int main() {
    int n, num = 1;
    scanf("%d", &n);
    Diamond_pattern(n, 1, true, &num);
    print_with_array(n);
    return 0;
}

