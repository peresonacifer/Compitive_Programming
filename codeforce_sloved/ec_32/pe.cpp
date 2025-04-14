#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int ans = 0, m;

void dfs(int st, int cur, vector<int>&v) {
    if(cur > ans) ans = cur;

    for(int i = st; i < v.size(); i++) {
        int cur2 = cur;
        cur = (cur + v[i]) % m;
        dfs(i + 1, cur, v);
        cur = cur2;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n >> m;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    dfs(0, 0, v);

    cout << ans << '\n';
    return 0;   
}

