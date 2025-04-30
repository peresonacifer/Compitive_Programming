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
    int n, k; cin >> n >> k;
    map<int, int> mp; 
    int ans = 0; 
    rep(i, n) {
        int x;
        cin >> x;
        if(mp.find(k - x) != mp.end()) {
            ans++;
            mp[k - x]--;
            if(mp[k - x] == 0) mp.erase(k - x);
        }
        else {
            mp[x]++;
        }
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