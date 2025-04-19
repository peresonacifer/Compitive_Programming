#include<bits/stdc++.h>
using namespace std;
using ll = long long;

map<int, int> mp;

void d(int n) {
    for (ll i = 2; i * i <= n; i++) {
        while(n % i == 0) {
            mp[i]++;
            n /= i;
        }
    }
    if (n > 1) mp[n]++;
}
void sol() {
    ll ori_n;
    int q;
    cin >> ori_n >> q;
    d(ori_n);
    
    while(q--) {
        int tq;
        cin >> tq;
        if (tq == 2) {
            mp.clear();
            d(ori_n);
        }
        else { 
            ll x, num_n = 1;
            cin >> x;
            d(x); 
            map<int, int> mp2(mp);
            for (auto it = mp2.begin(); it != mp2.end(); it++)
                num_n *= (it -> second + 1);
            for (auto it = mp2.begin(); it != mp2.end(); it++) {
                while (num_n % it -> first == 0 && it -> second) {
                    num_n /= it ->first;
                    it -> second--;
                }
            }

            if(num_n == 1) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    mp.clear(); 
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        sol();
    }
    return 0;
}