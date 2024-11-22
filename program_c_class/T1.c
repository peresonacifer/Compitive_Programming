#include<stdio.h>
#include<math.h>

float add(float arg_iNum1, float arg_iNum2, char agr_isround);
float divide(int arg_n1, int arg_n2);
void search_prime(int arg_iScope);

int main() {

    int iOpt;

    do{
        puts("<<This program have the following fuctions>>\n1. Arithemetic calculation.\n2. Prime number application.\n3. Recursive.\n4. Triangle distinguish.\n5. End program.");
        printf("%s", "Please input your option: ");
        scanf("%d", &iOpt);

        while (1) {
            switch (iOpt)
            {
            case 1:
                puts("1. +\n2. -\n3. *\n4. /5. %%\n6. bmi\n7. go back");
                while(1) {
                    int iSubOpt;
                    scanf("%d", &iSubOpt);
                    if(iSubOpt == 1) {
                        float fNum1, fNum2;
                        char cIsRound;
                        printf("%s", "please input 2 number and y/n to round seperately: ");
                        scanf("%f %f %c", &fNum1, &fNum2, &cIsRound);
                        
                        printf("ans: %.2f\n", add(fNum1, fNum2, cIsRound));
                    }
                    else if (iSubOpt == 2) {

                    }
                    else if (iSubOpt == 3) {

                    }
                    else if (iSubOpt == 4) {
                        int n1, n2; 
                        printf("%s", "please input two number: ");
                        scanf("%d %d", &n1, &n2);
                        printf("The ans is %.2f\n", divide(n1 ,n2));
                    }
                    else if (iSubOpt == 5) {
                        
                    }
                    else if (iSubOpt == 6) {
                        
                    }
                    else if (iSubOpt == 7) {
                        ;
                    }
                    else {
                        printf("%s", "wrong option, please input again: ");
                        while(getchar()!='\n');
                        scanf("%d", &iOpt);
                        continue;
                    }
                    break;
                }
                break;
            
            case 2:
                puts("1. search prime number\n2. prime factor\n3. prime number check\n4. greatest common factor\n5. smallest common multiple number\n6. go back");
                while(1) {
                    int iSubOpt;
                    scanf("%d", &iSubOpt);
                    if(iSubOpt == 1) {
                        int iscope;
                        printf("Please input the scope: ");
                        scanf("%d", &iscope);
                        while (iscope <= 0)
                        {
                            /* code */
                            printf("please input positive number: ");
                            scanf("%d", &iscope);
                        }
                        search_prime(iscope);
                        
                    }
                    else if (iSubOpt == 2) {

                    }
                    else if (iSubOpt == 3) {

                    }
                    else if (iSubOpt == 4) {
                        int n1, n2; 
                        printf("%s", "please input two number: ");
                        scanf("%d %d", &n1, &n2);

                    }
                    else if (iSubOpt == 5) {
                        
                    }
                    else if (iSubOpt == 6) {
                        ;
                    }
                    else {
                        printf("%s", "wrong option, please input again: ");
                        while(getchar()!='\n');
                        scanf("%d", &iOpt);
                        continue;
                    }
                    break;
                }
                break;
            case 3:
                puts("1. fab");
                break;
            case 4:   
                
                break;
            case 5:
                puts("This program is end.");
                break;

            default:
                printf("%s", "wrong option, please input again: ");
                while(getchar()!='\n');
                scanf("%d", &iOpt);
                continue;
            }
            break;
        }
        
    }while(iOpt != 5);

    return 0;
}

float add(float arg_fNum1, float arg_fNum2, char agr_isround) {
    if(agr_isround == 'y') {
        return (float)round(arg_fNum1 + arg_fNum2);
    }
    return arg_fNum1 + arg_fNum2;
}

float divide(int arg_n1, int arg_n2) {
    while(!arg_n2) {
        printf("denominator can't be zero, please input again: ");
        scanf("%d", &arg_n2);
    }
    return (float)arg_n1 / arg_n2;

}

void search_prime(int arg_iScope) {
    int t = 0;
    for(int i = 2; i <= arg_iScope; i++) {
        int isprimenumber = 1;
        for(int j = 2; j * j <= i; j++) {
            if(!(i % j)) {
                isprimenumber = 0;
                t++;
                break;
            }
        }
        if(isprimenumber)
            printf("%d ", i);
    }
    if(t == 0) {
        printf("No prime number in this range.");
    }
    puts("");
    return;
}
