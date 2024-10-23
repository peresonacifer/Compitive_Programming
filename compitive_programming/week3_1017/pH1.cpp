#include<bits/stdc++.h>
using namespace std;
using ll = long long;

map<int, int> mp;
vector<int> vct;

void d(int n) {
    for (int i = 2; i * i <= n; i++) {
        while(n % i == 0) {
            mp[i]++;
            n /= i;
        }
    }
    if (n > 1) mp[n]++;
}
void sol() {
    int ori_n, q;
    cin >> ori_n >> q;
    d(ori_n);
    vct.push_back(ori_n);
    while(q--) {
        int tq;
        cin >> tq;
        if (tq == 2) {
            mp.clear();
            vct.clear();
            vct.push_back(ori_n);
            d(ori_n);
        }
        else {
            int x, num_n = 1, d_n = 1;
            cin >> x;
            d(x); 
            vct.push_back(x);
            for (auto it = mp.begin(); it != mp.end(); it++)
                num_n *= (it -> second + 1);
            for (auto p : vct) 
                d_n *= (p % num_n);
            // cout << "n: " << n << ", num: " << num << '\n';
            if(d_n % num_n == 0) cout << "YES\n";
            else cout << "NO\n";
        }
    }
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