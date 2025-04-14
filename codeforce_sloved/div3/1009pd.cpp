#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t, n, m;
    ll ans;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        vector<int> x(n), r(n);
        for(int i = 0; i < n; i++) cin >> x[i];
        for(int i = 0; i < n; i++) cin >> r[i];
        map<int, int> mp;
        for(int i = 0; i < n; i++) {
            for(int j = -1 * r[i]; j <= r[i]; j++) {
                int y = sqrtl(1ll * r[i] * r[i] - 1ll * j * j);
                mp[x[i] + j] = max(mp[x[i] + j], 2 * y + 1);
            }
        }
        ans = 0;
        for(auto [a, b]: mp) {
            ans += b;
        }
        cout << ans << '\n';

    }
    return 0;
}