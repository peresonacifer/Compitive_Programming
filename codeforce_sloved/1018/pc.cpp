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
    int n; cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    rep(i, n) rep(j, n) cin >> grid[i][j];
    
    i64 ans = 0, inf = 1e17;
    rep(t, 2) {
        vector<int> c(n);
        rep(i, n) cin >> c[i];
        vector<i64> dp = {0, c[0]};
        for(int r = 1; r < n; r++) {
            vector<i64> ndp = {inf, inf};
            rep(pa, 2) {
                rep(ca, 2) {
                    bool ok = true;
                    rep(c, n) {
                        if(grid[r - 1][c] + pa == grid[r][c] + ca) ok = false;
                    }
                    if(ok) ndp[ca] = min(ndp[ca], dp[pa] + ca * c[r]);
                }
            }
            dp = ndp;
        }
        ans += min(dp[0], dp[1]);
        vector<vector<int>> tgrid(n, vector<int>(n));
        rep(i, n) rep(j, n) tgrid[i][j] = grid[j][i];
        grid = tgrid;
    }
    if(ans >= inf) cout << -1 << '\n';
    else cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T = 1; 
    cin >> T; 
    rep(i, T) sol();
    return 0;
}