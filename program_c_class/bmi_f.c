#include<stdio.h>

float bmi(int _weight, int _height);

int main(void) {
    int iHeightCM, iWeightKG;
    scanf("%d %d", &iWeightKG, &iHeightCM);
    printf("%.2f", bmi(iWeightKG, iHeightCM));
    return 0;
}

float bmi(int _weight, int _height) {
    float height = (float)_height / 100;
    return (float)_weight / (height * height);
}
