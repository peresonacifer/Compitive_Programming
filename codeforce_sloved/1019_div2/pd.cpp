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
    set<int> st1, st2;
    rep(i, n) {
        int x, y; cin >> x >> y;
        if(st1.count(x)) st1.erase(x);
        else st1.insert(x);
        if(st2.count(x + y)) st2.erase(x + y);
        else st2.insert(x + y);
    }
    cout << *st1.begin() << ' ' << *st2.begin() - *st1.begin()<< '\n';
}
//高級技巧
void sol2() {
    int n; cin >> n;
    int x = 0, y = 0;
    rep(i, n) {
        int a, b; cin >> a >> b;
        x ^= a;
        y ^= (a + b);
    }
    cout << x << ' ' << y - x << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T = 1; 
    cin >> T; 
    rep(i, T) sol2();
    return 0;
}