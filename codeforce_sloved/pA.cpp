#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int t;
    cin >> t;
    
    while (t--) {
        ll n, k, x;
        cin >> n >> k >> x;
        vector<ll> a(n);
        ll sumA = 0; // 整個 a 的總和
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sumA += a[i];
        }

        ll ans = 0;

        // 計算 `b` 陣列的前綴和，最大長度為 `n * min(k, 2)`，避免太大
        vector<ll> prefix(2 * n + 1, 0);
        for (int i = 1; i <= 2 * n; i++) {
            prefix[i] = prefix[i - 1] + a[(i - 1) % n];
        }

        // 滑動窗口，計算 `b` 中有多少個 `l` 滿足條件
        deque<int> dq;
        for (int i = 0; i < n * min(k, 2); i++) {
            while (!dq.empty() && prefix[i + 1] - prefix[dq.front()] >= x) {
                dq.pop_front();
            }
            dq.push_back(i);
            if (dq.front() < i - n * (k - 1)) dq.pop_front();
            if (!dq.empty()) ans += 1;
        }

        cout << ans << '\n';
    }
    return 0;
}
