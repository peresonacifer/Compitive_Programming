#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e7 + 1;
vector<int> prime;
bitset<maxn> N;

void init() {

    for(int i = 2; i < maxn; i++) {
        if(!N[i]) {
            prime.push_back(i);
        }
        for(int j = 0; i * prime[j] < maxn; j++) {
            N[i * prime[j]] = true;
            if(i % prime[j] == 0) break;
        }
    }
}
void solve() {
    int n, ans = 0;
    cin >> n;

    for(auto p: prime) {
        if(p > n) break;
        ans += n / p;
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    init();
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}