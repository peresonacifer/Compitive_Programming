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
    vector<int> a(n), b(n); rep(i, n) cin >> a[i];
    int cur = a[0];
    rep(i, n) {
        if(i == 0) b[i] = a[0];
        else b[i] = max(b[i - 1], a[i]);
    }
    i64 sum = 0;
    for(int i = n - 1; i >= 0; i--) {
        // cout << b[i] << " " << a[i] << '\n';
        if(b[i] > a[i]) {
            cout << 1ll * (sum + b[i]) << (i != 0 ? ' ' : '\n');;
        }
        else cout << 1ll * (sum + a[i])<< (i != 0 ? ' ' : '\n');;
        // cout << sum << (i != 0 ? ' ' : '\n');
        sum += a[i];
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T = 1; 
    cin >> T; 
    rep(i, T) sol();
    return 0;
}