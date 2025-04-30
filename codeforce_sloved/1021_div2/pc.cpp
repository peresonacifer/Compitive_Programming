#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
typedef pair<int, int> pii;
#define rep(i,n) for(i64 i=0; i<i64(n); i++)
#define push_back pb
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define F first
#define S second
template<typename A> void chmin(A& l, const A& r){ if(r < l) l = r; }
template<typename A> void chmax(A& l, const A& r){ if(l < r) l = r; }

void sol() {
    int n; cin >> n;
    map<int, int> mp;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x]++;
    }
    int cur = 0;
    bool ch = false;
    for(auto it = mp.begin(); it != mp.end(); it++) {
        if(it -> S >= 4) {
            cout << "Yes\n";
            return;
        }
        else if(it -> S >= 2 && !ch) {
            cur = it ->first;
            ch = true;
        }
        else if(it -> first - cur > 1 && ch) {
            ch = false;
            if(it -> S >= 2 && !ch) {
                cur = it ->first;
                ch = true;
            }
        }
        else if(it -> first - cur == 1 && ch) {
            if(it -> S >= 2) {
                cout << "Yes\n";
                return;
            }
            else cur++;
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