#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(m + 1, 0);
        vector<long long> s(m + 1, 0);
        for(int i = 1; i <= m; i++) {
            int x;
            cin >> x;
            a[i] = min(x, n - 1);
        }
        sort(a.begin() + 1, a.end());
        for(int i = 1; i <= m; i++) s[i] = s[i - 1] + a[i];
        long long ans = 0;
        for(int i = 1; i <= m; i++) {
            long long j = lower_bound(a.begin() + 1, a.end(), n - a[i]) - a.begin();
            if(j < i) ans += (a[i] - n + 1) * (i - j) + s[i - 1] - s[j - 1];
        }
        cout << ans * 2 << '\n';
    }
    return 0;
}