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
    int n, k; cin >> n >>  k;
    vector<int> a(n); rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    vector<pii> cnt;
    int m = n - k;
    if(m < n && m % 2) m++;
    
    if(m % 2) {
        // set<int> st;
        for(int i = 0; i <= n - m; i++) {
            cnt.pb({a[m / 2 + i], a[m / 2 + i]});    
        }
    }
    else {
        for(int i = 0; i <= n - m; i++) {
            cnt.pb({a[m / 2 - 1 + i], a[m / 2 + i]});
        }
    }

    sort(all(cnt));
    vector<pii> mg;
    for (auto [l, r] : cnt) {
        if (mg.empty() || mg.back().second < l) {
            mg.pb({l, r});
        } else {
            mg.back().second = max(mg.back().second, r);
        }
    }
    int ans = 0;
    for (auto [l, r] : mg) {
        ans += r - l + 1;
    }
    cout << ans << '\n'; 
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T = 1; 
    cin >> T; 
    rep(i, T) sol();
    return 0;
}