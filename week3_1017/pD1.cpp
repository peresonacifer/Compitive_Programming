// TLE
#include<bits/stdc++.h>

using namespace std;
using ll = long long;
void sol(ll n) {
    if (n == 1) {
        cout << "NO\n";
        return;
    }
    for (ll i = 2; i * i <= n; i++) {
        if (!(n % i)) {
            if (i * i == n) {
                cout << "YES\n";
                return;
            }
            else {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "NO\n";
}

int main () {
    ios::sync_with_stdio(0), cin.tie(0);
    ll t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        sol(n);
    }
    return 0;
}