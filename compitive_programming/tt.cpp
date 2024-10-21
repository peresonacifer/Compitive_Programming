#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void factorization(int n) {
    cout << n;
}

void sol() {
    map <int, int> mp;
    mp[1]++;
    mp[2] = mp[1] + 1;
    mp[3] = mp[2] + 1;
    for (auto it = mp.rbegin(); it != mp.rend(); it++) cout << it->second;
    cout << mp[1];
    // int n = 6;
    // float a = 6.1;
    // int b = a;
    // cout << b << '\n';
    // if (a > n) cout << "True";
    // for (int i = 0; i < 4; i++) {
    //     cin >> n;
    //     cout << n;
    // }

    // while(cin >> n && n!= 0) factorization(n);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    sol();
    return 0;
}