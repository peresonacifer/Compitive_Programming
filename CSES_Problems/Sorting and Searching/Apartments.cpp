#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m), vis(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int cur = 0;
    for(int i = 0; i < m; i++) {
        int pos = lower_bound(a.begin() + cur, a.end(), b[i] - k) - a.begin();
        if(pos == n) break;
        if(abs(a[pos] - b[i]) <= k) {
            ans++;
            cur = ++pos;
        }

    }

    cout << ans << '\n';
    
    return 0;
}