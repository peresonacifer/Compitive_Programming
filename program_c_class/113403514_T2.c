#include <stdio.h>

int main (void) {

    int iLengthOfSide[3];
    // Promot the user to input data and store it
    printf("Please enter the first lengths of three sides: ");
    scanf("%d", &iLengthOfSide[0]);
    printf("Please enter the second number lengths of three sides: ");
    scanf("%d", &iLengthOfSide[1]);
    printf("Please enter the third number lengths of three sides: ");
    scanf("%d", &iLengthOfSide[2]);
    // Check lengths of three sides. If there is one negative number, prompt user to input again.  
    for (int i = 0; i < 3; i++) {
        while (iLengthOfSide[i] <= 0) {
            printf("Please input a positive integer for %d lengths of three sides: ", (i + 1));
            scanf("%d", &iLengthOfSide[i]);
        }
    }
    puts("");

    for (int i = 0; i < 3; i++) {
        // Whether cannot form a triangle (a + b <= c) 
        if (iLengthOfSide[i] + iLengthOfSide[(i + 1)%3] <= iLengthOfSide[(i + 2)%3]) {
            puts("Cannot form a triangle.\n");
            puts("Program end.");
            return 0;
        }
        // Whether is a right triangle (a*a + b*b = c*c)
        if (iLengthOfSide[i]*iLengthOfSide[i] + iLengthOfSide[(i + 1)%3]*iLengthOfSide[(i + 1)%3] == iLengthOfSide[(i + 2)%3]*iLengthOfSide[(i + 2)%3]) {
            puts("A right triangle.\n");
            puts("Program end.");
            return 0;
        }        
    }
    puts("Not a right triangle.\n");
    puts("Program end.");
}
