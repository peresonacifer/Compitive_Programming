#include <stdio.h>
int main(void)
{
    int iScoreOfStudents[3];
    puts("Please enter the scores of 3 students:");
    for (int i = 0; i < 3; i++) {
        scanf("%d", &iScoreOfStudents[i]);
    }
    puts("");
    //check scores whether is between 0 and 100
    for (int i = 0; i < 3; i++) {
        if (iScoreOfStudents[i] < 0 || iScoreOfStudents[i] > 100) {
            puts("Sorry, all scores must be between 0 and 100\n");
            puts("Program ends");
            return 0;
        }
    }
    int iA = 0, iB = 0, iC = 0, iD = 0, iF = 0; // record the number of each five level
    for (int i = 0; i < 3; i++) {
        if (iScoreOfStudents[i] > 89) iA++;
        else if (iScoreOfStudents[i] > 79) iB++;
        else if (iScoreOfStudents[i] > 69) iC++;
        else if (iScoreOfStudents[i] > 59) iD++;
        else iF++;
    }
    // output the result
    puts("Grade distribution:");
    printf("A (90 and above): %d student(s)\n", iA);
    printf("A (89-90): %d student(s)\n", iB);
    printf("A (70-79): %d student(s)\n", iC);
    printf("A (60-69): %d student(s)\n", iD);
    printf("A (Below 60): %d student(s)\n\n", iF);

    puts("Program ends.");

    return 0;
}