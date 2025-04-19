#include<bits/stdc++.h>
using namespace std;
using ll = long long;

// 函數來計算質因數分解並返回質因數 map
map<int, int> factorize(int n) {
    map<int, int> mp;
    for (int i = 2; i * i <= n; i++) {
        while(n % i == 0) {
            mp[i]++;
            n /= i;
        }
    }
    if (n > 1) mp[n]++;
    return mp;
}

// 計算 d(n)，即正因數個數
ll divisor_count(map<int, int>& factors) {
    ll count = 1;
    for (auto& p : factors) {
        count *= (p.second + 1);
    }
    return count;
}

void sol() {
    int ori_n, q;
    cin >> ori_n >> q;
    
    // 儲存初始 n 的質因數
    map<int, int> overall_factors = factorize(ori_n);
    vector<int> numbers = {ori_n};
    
    while(q--) {
        int tq;
        cin >> tq;
        
        if (tq == 2) {
            // 重置質因數分解
            overall_factors = factorize(ori_n);
            numbers = {ori_n};
        } else {
            int x;
            cin >> x;
            
            // 將 x 的質因數加入到總的質因數中
            map<int, int> x_factors = factorize(x);
            for (auto& p : x_factors) {
                overall_factors[p.first] += p.second;
            }
            numbers.push_back(x);
            
            // 計算當前 n 的正因數個數
            ll num_n = divisor_count(overall_factors);
            
            // 用於檢查的數值計算 (可以根據具體題目修改)
            ll d_n = 1;
            for (int num : numbers) {
                d_n *= num % num_n;
            }
            
            // 輸出結果
            if (d_n % num_n == 0) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        sol();
    }
    
    return 0;
}
