#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        ll x;
        cin >> x;
        ll ans = 1;
        while(x > 3) {
            x /= 4;
            ans *= 1LL * 2;
        }
        cout << ans << '\n';
    }

    return 0;   
}

