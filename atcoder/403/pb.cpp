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
    string s1, s2;
    cin >> s1 >> s2;
    for(int i = 0; i <= s1.size() - s2.size(); i++) {
        bool ch = true;
        for(int j = i; j < i + s2.size(); j++) {
            if(s1[j] != '?' && s1[j] != s2[j - i]) ch = false;
        }
        if(ch) {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T = 1; 
    // cin >> T; 
    rep(i, T) sol();
    return 0;
}