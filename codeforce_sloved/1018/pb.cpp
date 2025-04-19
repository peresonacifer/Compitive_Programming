#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int t;
    cin >> t;
    
    while (t--) {
        int k, n;
        cin >> k >> n;
        vector<int> p(k);
        vector<pair<int, int>> v(k);
        for(int i = 0; i < k; i++) {
            cin >> v[i].first;
        }
        ll ans = 0;
        for(int i = 0; i < k; i++) {
            cin >> v[i].second;
            if(v[i].second > v[i].first) swap(v[i].first, v[i].second);
            ans += 1ll * v[i].first;
            p[i] = v[i].second;
        }
        sort(p.begin(), p.end(), greater<int>());
        for(int i = 0; i < n - 1; i++) ans += 1ll*p[i]; 
        cout << ++ans << '\n';
    }
    return 0;
}
