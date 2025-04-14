#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, w;
    cin >> n >> w;
    vector<pair<int, int>> v(n + 1);
    int maxv = 0;
    for(int i = 1; i <= n; i++) {
        cin >> v[i].first >> v[i].second;
        maxv += v[i].second;
    } 
    vector<int> dp(maxv + 1, w + 1);
    dp[0] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = maxv; j >= v[i].second; j--) { 
            dp[j] = min(dp[j], dp[j - v[i].second] + v[i].first);
        }
    }
    for(int i = maxv; i >= 1; i--) {
        if(dp[i] <= w) {
            cout << i << '\n';
            break;
        }
    }
    return 0;
}