#include<stdio.h>

int main() {
    int input,left=0,right=0,row,col;
    scanf("%d",&input);
    right=(input-1)*2;
    for(row=0;row<=(input-1)*2;row++) {
        for(col=0;col<=(input-1)*2;col++){
            if(col==left||col==right){
                printf("*");
            }
            else{
                printf(" ");
            }
        }
        left++;
        right--;
        printf("\n");
    }
    return 0;
}