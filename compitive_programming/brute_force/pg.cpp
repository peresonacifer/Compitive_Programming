#include<bits/stdc++.h>
using namespace std;
#define maxn 40
int ar[maxn], mod;
vector<int> v[2];

void dfs(int cur, int ed, int sum, int opt) {
    if(sum >= mod) sum %= mod;
    if(cur == ed) {
        v[opt].push_back(sum);
        return;
    }
    dfs(cur + 1, ed, sum + ar[cur], opt);
    dfs(cur + 1, ed, sum, opt);

}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, pos, ans = 0, mid;
    cin >> n >> mod;

    for(int i = 0; i < n; i++) {
        cin >> ar[i];
        if(ar[i] >= mod) ar[i] % mod;
    }
    mid = n / 2;

    dfs(0, mid, 0, 0);
    dfs(mid, n, 0, 1);
    for(int i = 0; i < 2; i++) sort(v[i].begin(), v[i].end());

    for(int i = 0; i < v[0].size(); i++) {
        pos = lower_bound(v[1].begin(), v[1].end(), mod - v[0][i]) - v[1].begin();
        if(v[1][pos - 1] + v[0][i] > ans) ans = v[1][pos - 1] + v[0][i];
    }
    cout << ans << '\n';
    return 0;
}