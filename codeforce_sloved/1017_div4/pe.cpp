#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void sol() {
    int n;
    cin >> n;
    vector<int> v(n), cnt(30, 0);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        for(int j = 0; j < 30; j++) {
            if(v[i] & (1 << j)) {
                cnt[j]++;
            }
        }
    }
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ll cur = 0;
        for(int j = 0; j < 30; j++) {
            if(v[i] & (1 << j)) {
                cur += (1LL << j) * (n - cnt[j]);
            }
            else {
                cur += (1LL << j) * cnt[j];
            }
        }
        ans = max(ans, cur);
    }
    cout << ans << '\n';
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