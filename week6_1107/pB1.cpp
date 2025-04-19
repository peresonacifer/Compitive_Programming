#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int ar[101];

void sol() {

    int n, m;
    cin >> n >> m;
    memset(ar, 0, m + 1);
    ar[0] = 1;
    while(n--) {
        int x, y;
        cin >> x >> y;
        for(int i = x + 1; i <= y; i++) {
            ar[i] = 1;
        }
    }
    
    for(int i = 0; i <= m; i++) {
        if(ar[i] == 0) {
            cout << "NO" << '\n';
            return;
        }
    }
    cout << "YES" << '\n';

    return;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int tc = 1;
    // cin >> tc;
    while(tc--) {
        sol();
    }
    return 0;
}