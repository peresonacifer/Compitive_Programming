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
    int n, k;
    cin >> n >> k;
    vector<int> a(n); 
    rep(i, n) {
        int x; cin >> x;
        a[i] = (x <= k ? 1 : -1);
    }   
    rep(i, 2) {
        vector<int> s(n + 1);
        for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i - 1];
        int p = -1;
        for(int i = 1; i <= n - 1; i++) {
            if(p > 0) {
                if(s[i] - s[p] >= 0 || s[n] - s[i] >= 0) {
                    cout << "Yes\n";
                    return;
                }
            }
            if(s[i] >= 0) {
                if(p == -1 || s[p] > s[i]) p = i;
            }
        }
        reverse(all(a));
    }
    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T; rep(i, T) sol();
    return 0;
}