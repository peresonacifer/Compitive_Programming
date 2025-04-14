#include<bits/stdc++.h>
#define Max 6e18
using namespace std;
using ll = long long;


void sol(ll a, ll b, ll c) {
    ll x = 1, y = 1, z = 1;
    for(ll x = 1; 3 * x * x <= Max && x + y + z <= a && x * y * z <= b && x * x + y * y + z * z <= c; x++) {
        for(ll y = x; 2 * y * y <= Max - x * x && x + y + z <= a && x * y * z <= b && x * x + y * y + z * z <= c; y++) {
            for(ll z = y; z * z <= Max - x * x - y * y && x + y + z <= a && x * y * z <= b && x * x + y * y + z * z <= c; z++) {
                if(x + y + z == a && x * y * z == b && x * x + y * y + z * z == c) {
                    cout << x << " " << y << " " << z << " " << '\n';
                    return;
                }
            }
        }
    }
    cout << "No solution.\n";
    return;
}
// 10^6
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    while(n--) {
        ll a, b, c;
        cin >> a >> b >> c;
        sol(a, b, c);
    }

    return 0;
}

