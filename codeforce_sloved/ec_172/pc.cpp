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
    int n, k; cin >> n >> k;
    vector<int> f(n + 1, 0); 
    string s; cin >> s;
    for(int i = n - 1; i >= 0; i--) {
        if(s[i] == '1') f[i] = f[i + 1] + 1;
        else f[i] = f[i + 1] - 1;
    }
    sort(f.begin() + 1, f.end(), greater());
    i64 sum = 0;
    for(int i = 1; i < n; i++) {
        sum += f[i];
        if(sum >= k) {
            cout << i + 1 << '\n';
            return;
        }
    }
    cout << -1 << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T = 1; 
    cin >> T; 
    rep(i, T) sol();
    return 0;
}