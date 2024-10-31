/*
題目2 -找出最大值/最小值/中位數•題目要求:1.鍵盤輸入一次任意多個數值•每個數值可用空白或其它符號分隔•
可以換行或者指定符號作為結束•需注意輸入非數值情況時之處理2.分別找出最大值/最小值/中位數並顯示於螢幕上。
*/

#include<stdio.h>

int main() {
    // if ((i = getchar()) == EOF) printf("EOF occur\n"); 
  
    // if(getchar() == EOF) printf("EoF occur\n"); /*OK*/

    // if (scanf("%d", &i) == EOF) printf("EOf occur\n"); //ps: my vscode success at third time

    /*
    //# getchar() and scanf() practical using
    while(scanf("%d", &a[i]) != EOF) {
        if((c = getchar()) != '\n' && c != ' ') {
            printf("%c is invaild value\n", c);
            continue;
        }
        printf("a[%d] = %d\n", i, a[i]);
        i++;
    }
    while ((c = getchar()) != EOF) printf("C: %c", c);
    printf("EOFF\n");
    */ 
    // scanf("%d", &i);
    // if ((c = getchar()) == '\n') printf("C == \\n "); 
    // explantion: scanf() can avoid " " and "\n", and when it work success , it stop after the value it stored 
    
    int a[1000], max, min, b[1000];
    float mid;
    int i = 0, k = 0;
    char c;

    
    while(1) {
        if(!scanf("%d", &a[i])) {
            b[k] = i;
            k++;
            getchar();
        }
        scanf("%c", &c);
        printf("c: %c", c);
        if (c == '\n') break;
        i++;
    }
    // printf("k = %d", k);
// 5 7 4 5 1
    for(int j = 0; j < k; j++) {
        int t = 0;
        do {
            if (t > 0) while(getchar() != '\n');
            printf("The %d input is invaid, please input a number: ", b[j] + 1);
            t++;
        } while(!scanf("%d", &a[b[j]]));
    }
    
    for(int h = i; h > 0; h--) {
        for(int m = 0; m < h; m++) {
            if(a[m] > a[m + 1]) {
                int tmp = a[m];
                a[m] = a[m + 1];
                a[m + 1] = tmp; 
            }
        }
    }
    //0 1 2 3 4 5
    //1 2 3 4 5 6
    if((i + 1) % 2 == 0) {
        mid = (float)(a[(i + 1) / 2 - 1] + a[(i + 1) / 2]) / 2;
    }
    else {
        mid = a[i / 2];
    }
    max = a[i], min = a[0];
    printf("max: %d\nmin: %d\nmid: %.2f\n", max, min, mid);

    return 0;
}