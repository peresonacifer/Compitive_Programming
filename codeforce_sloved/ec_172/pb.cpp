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
    int n; cin >> n;
    // vector<int> cnt(n + 1, 0);
    map<int, int> mp;
    rep(i, n) {
        int x;
        cin >> x;
        mp[x]++;
    } 
    int cnt = 0, ans = 0;
    for(auto x: mp) {
        if(x.second == 1) cnt++;
    }
    int t = mp.size() - cnt;
    ans += (cnt + 1 )/ 2;
    // if(ans % 2) t--;
    ans = t + ans * 2;
    // ans = (t - ans) + ans * 2;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T = 1; 
    cin >> T; 
    rep(i, T) sol();
    return 0;
}