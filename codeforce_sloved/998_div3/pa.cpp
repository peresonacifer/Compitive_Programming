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
    vector<int> a(4); rep(i, 4) cin >> a[i];
    int ans = 0;
    if(a[3] - a[2] == a[2] - a[1] && a[2] - a[1] == a[1] + a[0]) ans = 3;
    else if(a[3] - a[2] == a[2] - a[1] || a[2] - a[1] == a[1] + a[0] ||a[3] - a[2] == a[1] + a[0]) ans = 2;
    
    else ans = 1;

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T = 1; 
    cin >> T; 
    rep(i, T) sol();
    return 0;
}