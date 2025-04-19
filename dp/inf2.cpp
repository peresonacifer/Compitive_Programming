#include<bits/stdc++.h>
using namespace std;

int main() {
    int H, n;
    cin >> H >> n;
    vector<int> dp(H + 1, 1e8 + 1), A(n + 1), B(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> A[i] >> B[i];
    }
    dp[0] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= H; j++) {
            if(j + A[i] > H) {
                dp[H] = min(dp[H], dp[j] + B[i]);
            }
            else dp[j + A[i]] = min(dp[j + A[i]], dp[j] + B[i]);
        }
    }
    cout << dp[H] << '\n';
    return 0;
}