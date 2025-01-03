#include<stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int ar[n][m];
    for(int i = 0; i < n; i++) {
        for(int j =0; j < m; j++) {
            scanf("%d", &ar[i][j]);
        }
    }
    if(m == 1) printf("0\n");
    else{
        int assending, ans = 0;
        for(int i = 0; i < n; i++) {
            if(ar[i][0] < ar[i][1]) assending = 1;
            else assending = 0;
            for(int j = 1; j < m - 1; j++) {
                if(assending && ar[i][j] > ar[i][j + 1]) break;
                if(!assending && ar[i][j] < ar[i][j + 1]) break; 
                if(j == m - 2) ans++;
            }
        }
        printf("%d", ans);
    }

    return 0;
}