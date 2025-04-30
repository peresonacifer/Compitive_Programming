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
    vector<pii> n;
    int cnt = 0;
    int ch[3];
    rep(i , 3) {
        cin >> ch[i];        
        cnt += ch[i];
    }
    
    rep(i , 3) {
        int x;
        cin >> x;
        if(!ch[i]) continue;
        n.pb({x, ch[i]});
    }  
    vector<int> v(cnt/2);
    rep(i , cnt / 2) {
        int x;
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    sort(n.begin(), n.end());
    // int ans = 2e8 + 1;
    // cout << ans << '\n';
    if(n.size() == 1) {
        cout << (n[0].first + n[0].first) * v[0] << '\n';
        return;
    }
    for(int i = n.size() - 1; i > 0; i--) {
        n[i].S--;
        for(int k = i; k >= 0; k--) {
            if(n[k].S > 0) n[k].S--;
            else continue;    
            int mint;
            if(n[1].S > 1) mint = n[0].F;
            else mint = n[0].F + n[1].F;
            if((n[i].F + n[k].F) * v[0] <= mint * v[1]) {
                cout << (n[i].F + n[k].F) * v[0] << '\n';
                // cout << (n[i].F + n[k].F) <<  v[0] << '\n';
                return;
            }
            n[k].S++;
        }
        n[i].S++;
    }
    cout << n[0].F * 2 * v[1] << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T = 1; 
    // cin >> T; 
    rep(i, T) sol();
    return 0;
}