#include<bits/stdc++.h>
using namespace std;

using ll = long long;

priority_queue<int> pq1, pq2;

ll ans;

void sol() {
    ans = 0;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pq1.push(x);
    }
    for(int i = 0; i < n; i++) {
        int y;
        cin >> y;
        y *= -1;
        pq2.push(y);
    }
    for(int i = 0; i < n; i++) {
        ans += 1ll * pq1.top() * pq2.top() * -1;
        pq1.pop();
        pq2.pop();
    }
    return;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int tc;
    cin >> tc;
    for(int i = 1; i <= tc; i++){
        sol();
        cout << "Case #" << i << ": " << ans << '\n';
    }
    return 0;
}