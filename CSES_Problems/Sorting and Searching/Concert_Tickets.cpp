#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
typedef pair<int, int> pii;
#define rep(i,n) for(i64 i=0; i<i64(n); i++)
#define rep2(i,n) for(i64 i=1; i<=i64(n); i++)
#define push_back pb
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define first F
#define second S
template<typename A> void chmin(A& l, const A& r){ if(r < l) l = r; }
template<typename A> void chmax(A& l, const A& r){ if(l < r) l = r; }

void sol() {
    int n, m; cin >> n >> m;
    vector<int> a(n); rep(i, n) cin >> a[i];
    vector<int> p(n + 1); rep(i, n + 1) p[i] = i;
    sort(all(a));
    
    function<int(int)> find = [&](int pos) {
        return p[pos] == pos ? pos : (p[pos] = find(p[pos]));
    };

    rep(i, m) {
        int x; cin >> x;
        int pos = upper_bound(all(a), x) - a.begin() - 1;
        if(pos < 0) cout << -1 << '\n';
        else {
            pos = find(pos);
            if(pos == n) cout << -1 << '\n';
            else {
                cout << a[pos] << '\n';
                p[pos] = (pos == 0) ? n : pos - 1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T = 1; 
    // cin >> T; 
    rep(i, T) sol();
    return 0;
}