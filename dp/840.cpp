#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll cnt[9];
ll dp[9][10000];

int main() {
    ll w;
    cin >> w;    
    memset(dp, -1, sizeof(dp));    

    for(int i = 1; i <= 8; i++) cin >> cnt[i];
    dp[0][0] = 0;
    for(int i = 1; i <= 8; i++) {
        for(int j = 0; j <= 840 * i; j++) {
            if(dp[i - 1][j] != -1) {
                ll lim = 840 / i;
                lim = min(lim, cnt[i]);
                for(int k = 0; k <= lim; k++) {
                    dp[i][j + k * i] = max(dp[i][j + k * i], dp[i - 1][j] + (cnt[i] - k) / (840 / i));
                }
            }
        }
    }
    ll ans = 0;
    for(int i = 0; i <= 840 * 8 && i <= w; i++) {
        if(dp[8][i] == -1) continue;
        ans = max(ans, i + 840 * min(dp[8][i], (w - i) / 840));
    }
    cout << ans << '\n';
    return 0;
}