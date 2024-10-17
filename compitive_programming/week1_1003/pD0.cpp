#include <bits/stdc++.h>

#define F first
#define S second
#define ALL(x) begin(x), end(x)

using namespace std;
using pii = pair<int, int>;
using ll = long long;

void sol() {
    int n, p;
    cin >> n >> p;
    if (n == p) {
        cout << "\\";
        for (int i = 0; i < n; i++ ) {
            cout << "Y";
        }
        cout << "/";
        return;
    }    

    int d = (n - p) / (p - 1) + 1; 
    int r = (n - p) % (p - 1);
    cout << "\\";
    for (int i = 1; i < n + 1; i += d + (r-- > 0)) {
        cout << "Y";
        for (int j = i + 1; j < i + d + (r > 0) && j < n + 1; j++ ) {
            cout << "_";
        }
    }
    cout << "/";
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int tc = 1;
    //cin >> tc;
    while (tc--) {
        sol();
    }
    return 0;
}