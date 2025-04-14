#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll ans = 0;
        int n;
        cin >> n;
        ll x = n / 15;
        ans += x * 3;
        if(n >= x * 15) ans++;
        if(n >= x * 15 + 1) ans++;
        if(n >= x * 15 + 2) ans++;

        cout << ans << '\n';
    }

    return 0;
}

