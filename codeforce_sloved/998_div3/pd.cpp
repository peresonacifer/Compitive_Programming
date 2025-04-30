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
    vector<int> a(n); rep(i, n) cin >> a[i];
    rep(i, n - 1) {
        int x = min(a[i], a[i + 1]);
        a[i] -= x; a[i + 1] -= x;
        if(a[i] > a[i + 1]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T = 1; 
    cin >> T; 
    rep(i, T) sol();
    return 0;
}