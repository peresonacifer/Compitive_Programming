#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void factorization(ll n) {
    if (n < 2) {
        cout << n << " is not valid for factorization." << endl;
        return;
    }

    map<ll, int> factors;

    // 試著用每個小於sqrt(n)的數進行因數分解
    for (ll i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            factors[i]++;
            n /= i;
        }
    }
    
    // 如果剩下的 n 是質數且大於 1
    if (n > 1) {
        factors[n]++;
    }

    // 輸出因數
    for (auto it = factors.begin(); it != factors.end(); ++it) {
        cout << it->first << '^' << it->second;
        if (next(it) != factors.end()) {
            cout << ' ';
        }
    }
    cout << '\n';
}

void sol() {
    ll n;
    vector<ll> nums;
    while (cin >> n && n != 0) {
        nums.push_back(n);
    }
    for (auto it = nums.begin(); it != nums.end(); it++) factorization(*it);
}

int main() {
    sol();
    return 0;
}
