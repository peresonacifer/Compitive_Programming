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
    vector<i64> v(n);
    // i64 mint = 1e18;
    rep(i ,n) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    if(v[0] == v[1]) {
        cout << "Yes\n";
        return;
    }
    else {
        vector<i64> p;
        for(int i = 1; i < n; i++) {
            if(v[i] % v[0] == 0) {
                p.push_back(v[i]);
            }
        }
        for(int i = 0; i < p.size() - 1; i++) {
            for(int j = i + 1; j < p.size(); j++) {
                if(__gcd(p[i], p[j]) == v[0]) {
                    cout << "Yes\n";
                    return;
                }
            }
        }
    }
    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T = 1; 
    cin >> T; 
    rep(i, T) sol();
    return 0;
}