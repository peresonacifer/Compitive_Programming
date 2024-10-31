#include <stdio.h>

int main(void){
	while(1){
		int n;
		printf("Enter it：");
		if(scanf("%d",&n)==EOF){
			return 0;
		}
		
		int a[n][4];
		printf("Enter number：\n");
		int tem,i,j,k,w;
		for (i=0;i<n;++i){
			for (j=0;j<4;++j){	
				if(scanf("%d",&a[i][j])==EOF){
					return 0;
				}	
			}
		}
		
		for (i=0;i<n;++i){
			
			for (k=0;k<3;++k){
				for(w=0;w<3-i;++w){
					if(a[i][w]>a[i][w+1]){
						tem=a[i][w];	
						a[i][w]=a[i][w+1];
						a[i][w+1]=tem;
					}
				}
			}
			if(a[i][0] == a[i][1] && a[i][1] == a[i][2] && a[i][2] == a[i][3]){
				printf("Square");
			}
			else if(a[i][0]==a[i][1] && a[i][2]==a[i][3]){
				printf("Rectangle");
			}
			else if (a[i][0]+a[i][1]+a[i][2] > a[i][3]){
				printf("Quadrangle");
			}
			else{
				printf("Error");
			}
			puts("");
		}
	}
	return 0;
} 