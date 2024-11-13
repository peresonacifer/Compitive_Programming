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
        if(mp.find(y) != mp.end()) {
            if(x > mp[y]) mp[y] = x;
            else continue;
        }
        mp[y] = x;
    }

    for(auto it = mp.begin(); it != mp.end(); it++) {
        if(it -> second >= current) {
            current = it -> first;
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