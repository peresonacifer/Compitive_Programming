#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int t, n;
    int64_t ans;
    cin >> t;
    while(t--) {
        cin >> n;
        int ar[n];
        for(auto &x: ar) cin >> x; 
        vector<int64_t> pref(n + 1), suff(n + 1);
        for(int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + max(ar[i], 0);
        }

        for(int i = n - 1; i >= 0; i--) {
            suff[i] = suff[i + 1] - min(ar[i], 0);
        }
        ans = 0;
        for(int i = 0; i <= n; i++) ans = max(ans, pref[i] + suff[i]);
        cout << ans << '\n';
    }
    return 0;

}