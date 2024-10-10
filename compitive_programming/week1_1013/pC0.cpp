#include <bits/stdc++.h>

#define F first
#define S second
#define ALL(x) begin(x), end(x)

using namespace std;
using pii = pair<int, int>;
using ll = long long;

void sol() {
    int n;
    cin >> n;
    int cnt[26] = {0};
    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp; 
        for (auto c : tmp) cnt[c - 'a']++;
    }
    bool ans = true;
    for (int i = 0; i < 26; i++) if (cnt[i] == 0) ans = false;
    cout << (ans ? "Yes" : "No");
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