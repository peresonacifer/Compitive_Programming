#include<stdio.h>

int main(void){

    int iRow_number = -1, iColoum_number = -1;
    char cConfirm = 'n'; 
    puts("This program is for booking seat");
    
    do{
        //set the booked var as 0 for the status of booking seat(0 == flase, 1 == true)
        int booked = 0;  
        //the seating chart
        for(int i = 0; i <= 4; i++)
        {
            for(int j = 0; j <= 5; j++) 
            {
                if (i == 0) {
                    if (j == 0) printf("%3s", "");
                    else printf("C%d ", j);
                } 
                else {
                    if (i == iRow_number && j ==iColoum_number) {
                        printf("X%2s", "");
                        //set the booked as 1 due to seat booked
                        booked = 1;
                    }
                    else {
                        if (j == 0) printf("R%d ", i);
                        else printf("*%2s", "");
                    }
                }
            }
            puts("");
        }
        if (booked) {
            puts("X = Your seat");
            printf("%s", "Confirm seat [y/n]: ");
            while(getchar() != '\n');
            scanf("%c", &cConfirm);
            //cConfirm is only accepted to y or n. Input again until char is y or n
            while (cConfirm != 'y' && cConfirm != 'n') {
                puts("invalid option, just type y(YES) or n(NO).");
                printf("%s", "Confirm seat [y/n]: ");
                while(getchar() != '\n');
                scanf("%c", &cConfirm);
            }
        }
        
        if (cConfirm == 'n') {
            puts("Enter your seat row number: ");
            scanf("%d", &iRow_number);
            puts("Enter your seat column number: ");
            scanf("%d", &iColoum_number);    
           //check thw row_number and coloum_numner are in the correct range respectively
            while (( iRow_number < 1 || iRow_number > 4) || ( iColoum_number < 1 || iColoum_number > 5)) {
                puts("Your seat is out of range,\nrow number is between 1 to 4 and coloum number is between 1 to 5.");
                printf("%s", "Enter your seat row number: ");
                scanf("%d", &iRow_number);
                printf("%s", "Enter your seat column number: ");
                scanf("%d", &iColoum_number);
            }
        }
    } while (cConfirm != 'y');
    puts("Thank you for booking your seat.");

    return 0;
}

