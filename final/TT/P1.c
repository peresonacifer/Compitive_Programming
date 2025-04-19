#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>

int main() {
    
    int iOpt;
    do {
        printf("Please choose which option you want to do:\n1: Square pattern\n2: Diamond pattern with stars \n3: Standardize three numbers\n4: End program\n");
        scanf("%d", &iOpt);
        while (1) {
            switch (iOpt)
            {
            case 1:
                rectangle_pattern();
                puts("\n<back to top level menu>");
                break;
            case 2:
                diamond_pattern();
                puts("\n<back to top level menu>");
                break;
            case 3:
                standardize_three_number();
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