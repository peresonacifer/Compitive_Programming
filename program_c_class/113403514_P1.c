#include <stdio.h>
#include <math.h>

int main() {
    while(1) {
        int iOpt;
        printf("You have three option now.\n1. Buffet pricing.\n2. Sum of non-prime numbers.\n3. End program. \nInput your option: ");
        scanf("%d", &iOpt);
        // iOpt = 3 -> end
        if(iOpt == 3) break;
        // iOpt 1 or 3
        switch(iOpt) {
            case 1: {
                //iNumOA = the number of adult, iNumoC = the number of child
                int iDTP, iNumOA, iNumOC, idiscountTOF = 0, iPrice;
                float fTotalP;
                printf("Please enter the dinner time period:\n");
                scanf("%d", &iDTP);
                printf("Please enter the number of adults:\n");
                scanf("%d", &iNumOA);
                printf("Please enter the number of children:\n");
                scanf("%d", &iNumOC);
                puts("");

                //check the total people if >= 20, record idiscountTOF = 1, which means true. I set it 0 before
                if (iNumOA + iNumOC >= 20) {
                    idiscountTOF = 1;
                }
                // swithc the time period
                switch (iDTP) {
                    case 1: 
                        iPrice = 985;
                        fTotalP = iNumOA * iPrice + iNumOC * iPrice * 0.7;
                        
                        if(idiscountTOF) {
                            printf("Weekday Lunch $%d/person 5%% off\n", iPrice);
                            fTotalP *= 0.95;
                            fTotalP += fTotalP * 0.1;
                            printf("Total amount to be paid $%d\n", (int)round(fTotalP));
                        }
                        else {
                            printf("Weekday Lunch $%d/person\n", iPrice);
                            fTotalP += fTotalP * 0.1;
                            printf("Total amount to be paid $%d\n", (int)round(fTotalP));
                        }
                                        
                        break;
                    case 2:
                        iPrice = 795;
                        fTotalP = iNumOA * iPrice + iNumOC * iPrice * 0.7;
                        if(idiscountTOF) {
                            printf("Weekday Afternoon Tea $%d/person 5%% off\n", iPrice);
                            fTotalP *= 0.95;
                            fTotalP += fTotalP * 0.1;
                            printf("Total amount to be paid $%d\n", (int)round(fTotalP));
                        }
                        else {
                            printf("Weekday Afternoon Tea $%d/person\n", iPrice);
                            fTotalP += fTotalP * 0.1;
                            printf("Total amount to be paid $%d\n", (int)round(fTotalP));
                        }

                        break;
                    case 3:
                        iPrice = 1085;
                        fTotalP = iNumOA * iPrice + iNumOC * iPrice * 0.7;
                        if(idiscountTOF) {
                            printf("Weekday Dinner $%d/person 5%% off\n", iPrice);
                            fTotalP *= 0.95;
                            fTotalP += fTotalP * 0.1;
                            printf("Total amount to be paid $%d\n", (int)round(fTotalP));
                        }
                        else {
                            printf("Weekday Dinner $%d/person\n", iPrice);
                            fTotalP += fTotalP * 0.1;
                            printf("Total amount to be paid $%d\n", (int)round(fTotalP));
                        }       

                        break;             
                    case 4:
                        iPrice = 1085;
                        fTotalP = iNumOA * iPrice + iNumOC * iPrice * 0.7;
                        if(idiscountTOF) {
                            printf("Weekend Lunch $%d/person 5%% off\n", iPrice);
                            fTotalP *= 0.95;
                            fTotalP += fTotalP * 0.1;
                            printf("Total amount to be paid $%d\n", (int)round(fTotalP));
                        }
                        else {
                            printf("Weekend Lunch  $%d/person\n", iPrice);
                            fTotalP += fTotalP * 0.1;
                            printf("Total amount to be paid $%d\n", (int)round(fTotalP));
                        }

                        break;
                    case 5:
                        iPrice = 975;
                        fTotalP = iNumOA * iPrice + iNumOC * iPrice * 0.7;
                        if(idiscountTOF) {
                            printf("Weekend Afternoon Tea $%d/person 5%% off\n", iPrice);
                            fTotalP *= 0.95;
                            fTotalP += fTotalP * 0.1;
                            printf("Total amount to be paid $%d\n", (int)round(fTotalP));
                        }
                        else {
                            printf("Weekend Afternoon Tea $%d/person\n", iPrice);
                            fTotalP += fTotalP * 0.1;
                            printf("Total amount to be paid $%d\n", (int)round(fTotalP));
                        }

                        break;
                    case 6:
                        iPrice = 1195;
                        fTotalP = iNumOA * iPrice + iNumOC * iPrice * 0.7;
                        if(idiscountTOF) {
                            printf("Weekend Dinner $%d/person 5%% off\n", iPrice);
                            fTotalP *= 0.95;
                            fTotalP += fTotalP * 0.1;
                            printf("Total amount to be paid $%d\n", (int)round(fTotalP));
                        }
                        else {
                            printf("Weekend Dinner $%d/person\n", iPrice);
                            fTotalP += fTotalP * 0.1;
                            printf("Total amount to be paid $%d\n", (int)round(fTotalP));
                        }

                        break;
                    default:
                        break;
                }
                break;
            }
            case 2: {
                int iNumOint, iTotal = 0, iNum; 
                printf("Enter the number of integers: ");
                scanf("%d", &iNumOint);
                //the iteration is to store integers with the number of integers times
                for(int i = 1; i <= iNumOint; i++) {
                    int iTOF = 0;
                    printf("Enter integer %d: ", i);
                    scanf("%d", &iNum);
                    
                    //check iNum if < 0
                    while (iNum < 0) {
                        printf("Please enter a positive number.\n");
                        printf("Enter integer %d: ", i);
                        scanf("%d", &iNum);
                    }
                    // Check if have number can divide iNum
                    for (int i = 2; i * i <= iNum; i++) {
                        if (iNum % i == 0) {
                            iTOF = 1;
                            break;
                        }
                    }
                    if(iTOF || iNum == 1) {
                        iTotal += iNum;
                        iTOF = 0;
                    }
                }
                printf("The sum of non-prime integers is: %d\n", iTotal);
                break;

            }
            default: {
                break;
            }
        }
        printf("\n<back to the top level menu>\n");
    }
    printf("\nThe program end.\n");
    return 0;
}