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
    int n, d;
    cin >> n >> d;
    vector<int> v(n);
    unordered_map<int, int> mp;
    unordered_map<int, bool> vis;
    rep(i, n)  {
        cin >> v[i];
        mp[v[i]]++;
        vis[v[i]] = false;
    }
    int ans = 0;
    // sort(v.begin(), v.end());
    if(d == 0) cout << n - mp.size() << '\n';
    else {
        // vector<bool> vis(mp.size(), false);
        for(int i = 0; i < n; i++) {
            if(vis[v[i]]) continue;
            vis[v[i]] = true;
            
            vector<int> p;
            p.push_back(v[i]);
            int cur = v[i] + d;
            while(mp.find(cur) != mp.end())  {
                vis[cur] = true;
                p.push_back(mp[cur]);
                cur += d;
            }
            if(p.size() > 1) {
                vector<int> dp(p.size(), 0);
                dp[0] = p[0];
                if(p.size() >= 2) dp[1] = min(p[0], p[1]);
                for(int j = 2; j < p.size(); j++) dp[j] = min(dp[j - 1], dp[j - 2] + p[j]);
                ans += dp[p.size() - 1];
            }
            else {
                ans += p[0];
            }
        }
        cout << ans << '\n';
    }
    
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T = 1; 
    // cin >> T; 
    rep(i, T) sol();
    return 0;
}