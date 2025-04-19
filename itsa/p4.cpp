#include <bits/stdc++.h>
using namespace std;

#define Mod 1000000000

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> dp(n + 1);
    if(n < k) cout << 1 << '\n';
    else {
        dp[0] = 1;
        int sum = 1;
        for(int i = 1; i <= n ;i++) {
            dp[i - 1] = sum;
            if(i < k) {
                dp[i] = 1;
            }
            else if(i == k) {
                dp[i] = i;
            }
            else {
                dp[i] = (dp[i - 1] - dp[i - k - 1]) % Mod;
                if(dp[i] < 0) dp[i] += Mod;
            }
            sum = (sum + dp[i]) % Mod;
        }   
        cout << dp[n] << '\n';
    }
    return 0;
}