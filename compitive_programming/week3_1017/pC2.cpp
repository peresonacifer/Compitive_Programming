#include<bits/stdc++.h>
using namespace std;

using ll = long long;

void sol(ll n) {
    vector<pair<ll, int>> factors;

    for (ll i = 2; i * i <= n; i++) {
        for(int j = 0; !(n % i); n /= i) {
            if (n / i % i != 0) factors.push_back(make_pair(i, j + 1));
            else j++;
        }
    }
    if (n > 1) factors.push_back(make_pair(n, 1));

    for (int i = 0; i < factors.size(); i++) {
        cout << factors[i].first << '^' << factors[i].second;
        if (i < factors.size() - 1) cout << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll n;
    while(cin >> n && n != 0) {
        sol(n);
    }

    return 0;
}