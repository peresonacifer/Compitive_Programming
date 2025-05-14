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

int C(int n, int m) {

}
int mod = 1e9 + 7;
void sol() {
    int n, m, k;
    vector<pii> v(k);
    //read data
    //sort
    //v.pb(n - 1, m - 1);
    int dp[k + 1];
    for(int i = 0; i <= k; i++) {
        auto [x1, y1] = v[i];
        dp[i] = C(x1 + y1, x1);
        for(int j = 0; j < i; j++) {
            auto [x2, y2] = v[j];
            if(y1 < y2) continue;
            dp[i] -= C(x1 - x2 + y1 - y2, x1 - x2) * dp[j] % mod;
            dp[i] = (dp[i] + mod) % mod; 
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T = 1; 
    cin >> T; 
    rep(i, T) sol();
    return 0;
}