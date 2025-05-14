#include<bits/stdc++.h>
using namespace std;

void sol(int n, int k) {
    int P, N; 
    int dp[P + 1][N + 1], dis[N + 1][N + 1], r[P + 1][N + 1];

    
    for(int i = 0; i <= N; i++) dp[0][i] = (i == 0 ? 0 : INT32_MAX);
    for(int p = 1; p <= P; p++) {
        for(int n = p; n <= N; n++) {
            dp[p][n] = INT32_MAX;
            for(int i = p; i <= n; i++) {
                dp[p][n] = min(dp[p][n], dp[p - 1][i - 1] + dis[i][n]);
                r[p][n] = i;
            }
        }
    }
// r[P][N] = k1, r[P - 1][k1 - 1] = k2....
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, k;
    while(cin >> n >> k && n && k) sol(n, k);
    return 0;
}