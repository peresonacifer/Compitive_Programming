#include<stdio.h>

int main(void){

    int iVar_1, iVar_2, iOperation;
    puts("Enter First number:");
    scanf("%d", &iVar_1);
    puts("Enter second number:");
    scanf("%d", &iVar_2);
    
    do {
    puts("- Select one operation\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. End program");
    scanf("%d", &iOperation);
    switch(iOperation){
    case 1:
        printf("First numeber + second number = %d\n", iVar_1 + iVar_2);
        break;
    case 2:
        printf("First numeber - second number = %d\n", iVar_1 - iVar_2);
        break;
    case 3:
        printf("First numeber * second number = %d\n", iVar_1 * iVar_2);
        break;
    case 4:
        printf("First numeber / second number = %.2f\n", (float)iVar_1 / iVar_2);
        break;
    case 5:
        puts("Bye Bye\n(Program terminated)");
        break;
    default:
        puts("invalid value, please select operation\n");
    }//end of switch statement
    }while(iOperation != 5);

    return 0;
}