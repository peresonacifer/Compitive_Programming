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
    i64 sum = 0;
    vector<int> v(3);
    for(int i = 0; i < 3; i++) {
        // int x;
        cin >> v[i];
        sum += v[i];
    }
    if(sum % 3 != 0) cout << "No\n";
    else {
        int av = sum / 3;
        if(v[1] > av || v[0] > av) cout << "No\n";
        else cout << "Yes\n";
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T = 1; 
    cin >> T; 
    rep(i, T) sol();
    return 0;
}