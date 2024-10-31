#include<stdio.h>

int main(void) {

    int iTotal = 0, iGradeCounter = 1, iNumOfGrades;
    char c;

    // 提示使用者按下Enter後進入程式
    puts("Press Enter to start the program or input -1 to end the program.");
    c = getchar();  // 等待使用者按下Enter

    if (c == '\n') {  // 如果按下Enter則開始程式
        puts("How many students?");
        scanf("%d", &iNumOfGrades);
        
        // 檢查使用者是否輸入了 -1 終止程式
        if (iNumOfGrades == -1) {
            puts("Program terminated by user.");
            return 0;
        }

        while (iNumOfGrades <= 0 ) {
            if (iNumOfGrades == 0) {
                puts("This program is end because no student");
                return 0;
            } else {
                puts("Invalid data. Please input the number of students again or input -1 to end the program.");
                scanf("%d", &iNumOfGrades);
                
                // 檢查是否輸入了 -1
                if (iNumOfGrades == -1) {
                    puts("Program terminated by user.");
                    return 0;
                }
            }
        } 

        // 依次輸入每個學生的成績
    
        while (iGradeCounter < iNumOfGrades + 1) {
            int iCurrentGrade = 0;
            printf("Enter grade of student %d: ", iGradeCounter);
            scanf("%d", &iCurrentGrade);
            
            while (iCurrentGrade < 0 || iCurrentGrade > 100) {
                printf("Invalid data. Please input the grade of student %d in the range 0 to 100 or input -1 to end the program: ", iGradeCounter);
                scanf("%d", &iCurrentGrade);

                // 檢查是否輸入了 -1
                if (iCurrentGrade == -1) {
                    puts("Program terminated by user.");
                    return 0;
                }
            }
            iTotal += iCurrentGrade;
            iGradeCounter++;
        }

        // 計算並顯示平均值
        printf("The class average = %.2f\n", (float)iTotal / iNumOfGrades);
    } else {
        puts("Program terminated by user.");
    }

    return 0;
}
