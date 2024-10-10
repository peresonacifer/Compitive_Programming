#include<stdio.h>

int main(void) {

    int iTotal = 0, iGradeCounter = 1, iNumOfGrades;
    puts("How many students?");
    scanf("%d", &iNumOfGrades);
    while (iNumOfGrades <= 0 ) {
        if (iNumOfGrades == 0) {
            puts("This program is end because no student");
            return 0;
        }
        else {
            puts("Invaild data, please input the number of students again!");
            scanf("%d", &iNumOfGrades);
        }
    } 

    while (iGradeCounter < iNumOfGrades + 1) {
        int iCurrentGrade = 0;
        printf("Enter grade of student %d: ", iGradeCounter);
        scanf("%d", &iCurrentGrade);
        while (iCurrentGrade < 0 || iCurrentGrade > 100) {
            printf("%s", "Invaild data, please input the grade of student %d in the range 1 to 100: ", iGradeCounter);
            scanf("%d", &iCurrentGrade);
        }
        iTotal += iCurrentGrade;
        iGradeCounter ++;
    }

    printf("The class average = %.2f", (float)iTotal / 10);
    return 0;
}