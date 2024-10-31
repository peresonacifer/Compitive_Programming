#include<stdio.h>

int main(void){

    int iRow_number = -1, iColoum_number = -1;
    char cConfirm = 'n'; 
    puts("This program is for booking seat");
    
    do{
        int booked = 0;
        for(int i = 0; i <= 4; i++)
        {
            for(int j = 0; j <= 5; j++) 
            {
                if (i == 0) {
                    if (j == 0) printf("   ");
                    else printf("C%d ", j);
                } 
                else {
                    if (i == iRow_number && j ==iColoum_number) {
                        printf("X  ");
                        booked = 1;
                    }
                    else {
                        if (j == 0) printf("R%d ", i);
                        else printf("*  ");
                    }
                }
            }
            printf("\n");
        }
        if (booked) {
            puts("X = Your seat");
            printf("Confirm seat [y/n]: ");
            while(getchar() != '\n');
            scanf("%c", &cConfirm);
            while (cConfirm != 'y' && cConfirm != 'n') {
                puts("invalid option, just type y(YES) or n(NO).");
                printf("Confirm seat [y/n]: ");
                while(getchar() != '\n');
                scanf("%c", &cConfirm);
            }
        }
        
        if (cConfirm == 'n') {
            printf("Enter your seat row number: ");
            scanf("%d", &iRow_number);
            printf("Enter your seat column number: ");
            scanf("%d", &iColoum_number);    
            while (( iRow_number < 1 || iRow_number > 4) || ( iColoum_number < 1 || iColoum_number > 5)) {
                puts("Your seat is out of range,\nrow number is between 1 to 4 and coloum number is between 1 to 5.");
                printf("Enter your seat row number: ");
                scanf("%d", &iRow_number);
                printf("Enter your seat column number: ");
                scanf("%d", &iColoum_number);
            }
        }
    
    } while (cConfirm != 'y');
    puts("Thank you for booking your seat.");

    return 0;
}
