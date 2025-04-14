#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll ans = 0;
        
        ll n, x, k;
        ll t = 0;
        cin >> n >> x >> k;
        string s;
        cin >> s;
        if(x == 0) ans++;

        for(int i = 0; i < n; i++) {
            if(s[i] == 'L') x -= 1;
            else x += 1;
            t++;
            if(x == 0) {
                ans++;
                break;
            }
        }

        if(x != 0 || t >= k ) {
            cout << ans << '\n';
            continue;
        }

        int period = 0;
        for(int i = 0; t < k && i < n; i++) {
            if(s[i] == 'L') x -= 1;
            else x += 1;
            t++;
            if(x == 0) {
                ans++;
                period = i + 1;
                break;
            }
        }
        if(period) ans += (k - t) / period;
        cout << ans << '\n';

    }

    return 0;
}

