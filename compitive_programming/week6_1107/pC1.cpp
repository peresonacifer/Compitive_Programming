#include<bits/stdc++.h>
using namespace std;

using ll = long long;

map<int, int> mp;
int ans = 0, current = 0;

void sol() {

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        mp[x] = y;
    }

    for(auto it = mp.begin(); it != mp.end(); it++) {
        if(it -> first >= current) {
            current = it -> second;
            ans++;
        }
    }

    cout << ans << '\n';
    return;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int tc = 1;
    while(tc--) {
        sol();
    }
    return 0;
}