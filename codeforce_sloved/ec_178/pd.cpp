#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
typedef pair<int, int> pii;
#define rep(i,n) for(int i=0; i < n; i++)
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define F first
#define S second
template<typename A> void chmin(A& l, const A& r){ if(r < l) l = r; }
template<typename A> void chmax(A& l, const A& r){ if(l < r) l = r; }
const int N = 6e6 + 5; // k ~ n / ln n
bitset<N> is_prime; 
vector<int> prime;

void init() {
    for (int i = 2; i <= N && sz(prime) <= int(4e5); ++i) {
        if (!is_prime[i]) {
            prime.push_back(i);
        }
        for(int j = 0; j < sz(prime) && prime[j] * i <= N && sz(prime) <= int(4e5); j++) {
            is_prime[prime[j] * i] = 1;
            if(i % prime[j] == 0) break;
        }
    }
}

void sol() {
    int n; cin >> n;
    vector<int> a(n); 
    rep(i, n) cin >> a[i];
    sort(all(a), greater());
    i64 sum = 0;
    int ans = 1;
    rep(i, n) {
        sum += a[i] - prime[i];
        if(sum >= 0) ans = i + 1; 
    }
    cout << n - ans << '\n';
    
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T = 1; 
    cin >> T; 
    init();
    rep(i, T) sol();
    return 0;
}