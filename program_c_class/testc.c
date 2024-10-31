#include <stdio.h> 
int main(void){
    int end_idx = -1; 
    char EndOProgram;
    
    do {
        printf("Enter some nunbers(-1 end):");
        int a[100];
        for (int i = 0; scanf("%d", &a[i]) && a[i] != -1; i++) {
            for (int j = i; j != 0; j--) {
                if (a[j] > a[j - 1]) {
                    int tmp = a[j];
                    a[j] = a[j - 1];
                    a[j - 1] = tmp;   
                }
                else break;
            }
            end_idx = i;
        }
        if (end_idx > -1) {
            printf("%s", "\nThe numbers are arranged from largest to smallest :");
            for (int i = 0; i <= end_idx; ++i){
                printf("%d ",a[i]);
            } 
            end_idx = -1;   
        }
        while(getchar() != '\n');
        puts("\ninput ctrl + z to end program or press others to keep going: ");

    } while((EndOProgram = getchar()) != EOF);

    return 0; 
}