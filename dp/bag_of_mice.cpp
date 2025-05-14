#include<bits/stdc++.h>
using namespace std;
#define ld long double
void sol() {
    int w, b;
    long double dp[w + 1][b + 1];
    for (int i = 1; i <= w; i++) dp[i][0] = 1; // 全白
    for (int i = 1; i <= b; i++) dp[0][i] = 0; // 全黑

    for(int i = 1; i <= w; i++) {
        for(int j = 1; j <= b; j++) {
            dp[i][j] = (ld)i / (i + j);
            if(j >= 3) dp[i][j] += (ld)j / (i + j) * (ld)(j - 1) / (i + j - 1) * (ld)(j - 2) / (i + j - 2) * dp[i][j - 3];  
        
            if(i >= 1 && j >= 2) dp[i][j] += j / (i + j) * (j - 1) / (i + j - 1) * (i) / (i + j - 2) * dp[i - 1][j - 2];
        }
    }


}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    sol();
    return 0;
}