#include <stdio.h>
#include <stdbool.h>

void printNumberSquare(int _iSizeOfSquare);
void printNumberSquare_v2(int _iSizeOfSquare, bool _bIsSquence);

int main(void){

//    int iCount = 0;
    int iSizeOfSquare = 11;
    printNumberSquare(iSizeOfSquare);

    puts("==== v2 =====");

    printNumberSquare_v2(iSizeOfSquare, true);

/*
    for (int i=1; i<=iSizeOfSquare; i++){ //loop thru rows
        for (int j=1; j<=iSizeOfSquare; j++){ //loop thru columns
            iCount++;
            if (iCount < 10){
                printf(" %d ", iCount);
            } else {
                printf("%d ", iCount);
            }
            if (iCount % iSizeOfSquare == 0){ //print \n at the end of row.
                puts("");
            }
        }//end for j
    }//end for i
*/
}//end main

void printNumberSquare(int _iSizeOfSquare){
    int iCount = 0;
    for (int i=1; i<=_iSizeOfSquare; i++){ //loop thru rows
        for (int j=1; j<=_iSizeOfSquare; j++){ //loop thru columns
            iCount++;
            if (iCount < 10){
                printf("%3d ", iCount);
            } else {
                printf("%3d ", iCount);
            }
            if (j % _iSizeOfSquare == 0){ //print \n at the end of row.
                puts("");
            }
        }//end for j
    }//end for i
}//end printNumberSquare

void printNumberSquare_v2(int _iSizeOfSquare, bool _bIsSquence){

    int iCount = 0;
    for (int i=1; i<=_iSizeOfSquare; i++){ //loop thru rows
        for (int j=1; j<=_iSizeOfSquare; j++){ //loop thru columns
            if (!(_bIsSquence)){ iCount = 1; }
            else { iCount++; }
            
            if (iCount < 10){
                printf(" %d ", iCount);
            } else {
                printf("%d ", iCount);
            }
            if (j % _iSizeOfSquare == 0){ //print \n at the end of row.
                puts("");
            }
        }//end for j
    }//end for i
}//end printNumberSquare_v2