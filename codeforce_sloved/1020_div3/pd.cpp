#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
typedef pair<int, int> pii;
#define rep(i,n) for(i64 i=0; i<i64(n); i++)
#define push_back pb
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define first F
#define second S
template<typename A> void chmin(A& l, const A& r){ if(r < l) l = r; }
template<typename A> void chmax(A& l, const A& r){ if(l < r) l = r; }

void sol() {
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];
    vector<int> pre(m + 1, n + 1), suf(m + 1, -1); 
    pre[0] = 0;
    for(int i = 0, j = 0; i < m; i++) {
        while(j < n && a[j] < b[i]) j++;
        if(j == n) break;
        pre[i + 1] = ++j;
    }
    suf[m] = n;
    for(int i = m - 1, j = n - 1; i >= 0; i--) {
        while(j >= 0 && a[j] < b[i]) j--;
        if(j < 0) break;
        suf[i] = j--;
    }
    if(pre[m] <= n) {
        cout << "0\n";
        return;
    }
    int inf = 1e9 + 1;
    int ans = inf;
    for(int i = 0; i < m; i++) {
        if(pre[i] <= suf[i + 1]) {
            ans = min(ans, b[i]);
        }
    }
    if(ans == inf) cout << -1 << '\n';
    else cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T = 1; 
    cin >> T; 
    rep(i, T) sol();
    return 0;
}