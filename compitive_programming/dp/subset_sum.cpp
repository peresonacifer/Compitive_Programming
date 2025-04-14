#include<bits/stdc++.h>
using namespace std;
int dp[3005];

int main() {
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    int s[2], w[2];
    w[0] = a, w[1] = b;
    s[0] = c, s[1] = d;
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j <= f - w[i] * 100; j++) {
            dp[j + w[i] * 100] = max(dp[j + w[i] * 100], dp[j]);
        }
    }

    for(int j = 0; j <= f; j++)  {
        if(dp[j] == -1) continue;
        for(int i = 0; i < 2; i++) {
            for(int k = 1; (dp[j] + k * s[i]) * 100 <= (j - dp[j]) * e && j + k * s[i] <= f; k++) {
                dp[j + k * s[i]] = max(dp[j + k * s[i]], dp[j] + k * s[i]);
            }
        }   
    }
    int id = 1;
    pair<int, int> ans;
    for(int i = 2; i <= f; i++) {
        if(dp[i] * (id - dp[id]) > dp[id] * (i - dp[i])) {
            ans = {i, dp[i]};
            id = i;
        }
    }
    cout << ans.first << " " << ans.second << '\n';

    return 0;
}