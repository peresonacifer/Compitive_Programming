#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;
ll ans;
void solve() {
    int N, nodd = 0;
    cin >> N;
    vector<ll> v(N);
    ans = 0;
    for(auto &p : v) {
        cin >> p;
        if(p & 1) nodd++;
        ans += p / 2;
    }
    if(nodd == 0 || nodd == N) {
        ans = *max_element(v.begin(), v.end());
    }
    else {
        ans = ans * 2 + 1;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}