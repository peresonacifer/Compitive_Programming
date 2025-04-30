#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
typedef pair<int, int> pii;
#define rep(i,n) for(i64 i=0; i<i64(n); i++)
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define F first
#define S second
template<typename A> void chmin(A& l, const A& r){ if(r < l) l = r; }
template<typename A> void chmax(A& l, const A& r){ if(l < r) l = r; }

void sol() {
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    rep(i, n) rep(j, m) cin >> a[i][j];
    vector<pii> p;
    rep(i, n) {
        sort(all(a[i]));
        p.pb({a[i][0], i});
    }
    sort(all(p));
    int cur = 0;
    // rep(i, n) rep(j, m) cout << a[i][j] << " ";
    
    
    rep(j, m) {
        rep(i, n) {

            // cout << a[p[i].S][j] << " " << cur << '\n';
            if(a[p[i].S][j] != cur++) {
                cout << -1 << '\n';
                return;
            }
        }
    }
    
    rep(i, n) {
        cout << p[i].S + 1 << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T = 1; 
    cin >> T; 
    rep(i, T) sol();
    return 0;
}