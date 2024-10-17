/*
    This program can convert Celsius to Fahrenheit and vice versa, with a menu feature for users to choose the conversion type.
    This program cannot handle non-numeric characters when entering temperature.
*/
#include <stdio.h>
int main(void)
{
    int iOpt;
    float fTemperature;
    // Program description and menu
    printf("This program converts temperature in Celsius into Fahrenheit and vice versa.\n");
    printf("Enter 1 or 2 for conversion:\n1: Celsius to Fahrenheit\n2: Fahrenheit to Celsius\n");
    
    
    while (scanf("%d", &iOpt) != 1 || (iOpt != 1 && iOpt != 2)) {  
        printf("This option does not exist! Please try again.\n");
        while(getchar() != '\n');
    }

    
    if (iOpt == 1)
    {
        printf("Enter a temperature in Celsius:\n");
        while (scanf("%f", &fTemperature) != 1) 
        {
            while(getchar() != '\n');
            printf("invalid value, please input numeric!!!\n");
        }
        printf("%.1f degrees Celsius is %.2f degrees in Fahrenheit.\n", fTemperature, fTemperature*9/5 + 32);    
    }
    else
    {
        printf("Enter a temperature in Fahrenheit:\n");
         while (scanf("%f", &fTemperature) != 1) 
        {
            while(getchar() != '\n');
            printf("invalid value, please input numeric!!!\n");
        }
        printf("%.1f degrees Fahrenheit is %.2f degrees in Celsius\n", fTemperature, (fTemperature - 32)*5/9);
    }

}