#include<stdio.h>
#include<math.h>

//rectangle fuction
void rectangle_pattern() {
    int irows, icolums;
    printf("please input the number of rows: ");
    scanf("%d", &irows);
    printf("please input the number of rows: ");
    scanf("%d", &icolums);

    int asending = 1, ians = 0;
    for(int i = 1; i <= irows; i++) {
        for(int j = 1; j <= icolums; j++) {
            if(asending) {
                ians++;
                printf("%d ", ians);
            }

            else {
                ians--;
                printf("%d ", ians);
            }
            if(ians == 9 && asending == 1) {
                asending = 0;
            }
            if(ians == 1 && asending == 0) {
                asending = 1;
            }
        }
        puts("");
    
    }
    return;
}

//diamond fuction
void diamond_pattern() {
    int ilayers;
    printf("please enter the number of layers of diamond: ");
    scanf("%d", &ilayers);
    int asending = 1, ians = 0, left = (ilayers + 1) / 2, right = (ilayers + 1) / 2;
    for(int i = 1; i <= (ilayers + 1) / 2; i++) {
        
        for(int k = i; k < (ilayers + 1) / 2 ; k++) {
            printf("  ");
        }
        for(int j = 1; j <= ilayers - 2 * ((ilayers + 1) / 2 - i); j++) {
            if(j % 2) {
                if(asending) {
                ians++;
                printf("%d ", ians);
                }
                else {
                    ians--;
                    printf("%d ", ians);
                }

                if(ians == 9 && asending == 1) {
                    asending = 0;
                }
                if(ians == 1 && asending == 0) {
                    asending = 1;
            }
            }
            else {
                printf("* ");
            }
            
        }
        puts("");
    }

    for(int i = (ilayers + 1)/2 + 1; i <= ilayers; i++) {
        for(int k = i; k > (ilayers + 1) / 2 ; k--) {
            printf("  ");
        }
        for(int j = 1; j <= 2 * (ilayers - i + 1) - 1; j++) {
            if(j % 2) {
                if(asending) {
                ians++;
                printf("%d ", ians);
                }
                else {
                    ians--;
                    printf("%d ", ians);
                }

                if(ians == 9 && asending == 1) {
                    asending = 0;
                }
                if(ians == 1 && asending == 0) {
                    asending = 1;
            }
            }
            else {
                printf("* ");
            }
            
        }
        puts("");
    }
    return;

}
double calculate_mean(double _iNum1, double _iNum2, double _iNum3) {
    double daverage = (_iNum1 + _iNum2 + _iNum3)/3;
    return daverage;
}
double calculate_stddev(double _iNum1, double _iNum2, double _iNum3, double _daverage) {
    double dsigma = sqrt(((_iNum1 - _daverage) * (_iNum1 - _daverage) + (_iNum2 - _daverage) * (_iNum2 - _daverage) + (_iNum3 - _daverage) * (_iNum3 - _daverage)) / 3);
    return dsigma;
}

unsigned int fab(int n) {
    if(n == 1 || n == 0) {
        return n;
    }

    return fab(n - 1) + fab(n - 2);
}

void callfab() {
    int n;
    printf("please input n: ");
    scanf("%d", &n);
    printf("fab(%d) = %u", n, fab(n));
    return;
}

void standardize_three_number() {

    printf("please enter three integers:\n");
    double iNum1, iNum2, iNum3;
    scanf("%lf %lf %lf", &iNum1, &iNum2, &iNum3);
    double dAverage = calculate_mean(iNum1, iNum2, iNum3);
    double dSigma = calculate_stddev(iNum1, iNum2, iNum3, dAverage); 
    
    puts("\nstandardized numbers: ");
    printf("z1 = %.3lf\nz2 = %.3lf\nz3 = %.3lf\n", (iNum1 - dAverage) / dSigma, (iNum2 - dAverage) / dSigma, (iNum3 - dAverage) / dSigma);
    return;
}

int main() {
    
    int iOpt;
    do {
        printf("Please choose which option you want to do:\n1: Square pattern\n2: Diamond pattern with stars \n3: Standardize three numbers\n4: fabnocci\n5: End program\n");
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
                callfab();
                puts("\n<back to top level menu>");
                break;
            case 5:
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