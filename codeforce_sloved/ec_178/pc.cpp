#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    bool has_non2 = false;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x != 2) has_non2 = true;
    }
    if (has_non2) cout << 0 << "\n";
    else cout << 1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
