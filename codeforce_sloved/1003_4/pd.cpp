#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void sol() {
    int n, m;
    cin >> n >> m;
    vector<ll> v(n);
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ll cnt = 0;
        for(int j = 1; j <= m; j++) {
            ll x;
            cin >> x;
            cnt += x;
            ans += cnt;
        }
        v[i] = cnt;
    }
    
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++) {
        ans += v[i] * i * m;
    }
    cout << ans << '\n';
    return;
}


int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        sol();
    }
    return 0;   
}

