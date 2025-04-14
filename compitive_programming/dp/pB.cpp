#include<bits/stdc++.h>
using namespace std;

const int mx = 1e6 + 1;
int main() {
    int n, x;
    cin >> n >> x;
    int coins[n] = {};
    for(int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    vector<int> dp(x + 1, mx);
    dp[0] = 0;
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < n; j++) {
            if((i + coins[j]) <= x) dp[i + coins[j]] = min(dp[i + coins[j]], dp[i] + 1);
        }
    }
    cout << ((dp[x] >= mx) ? -1 : dp[x]) << '\n';

    return 0;
}
