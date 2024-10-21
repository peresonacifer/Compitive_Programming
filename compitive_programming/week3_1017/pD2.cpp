#include<bits/stdc++.h>
using namespace std;

#define N 1000001

using ll = long long;

set<ll> myset;

void sol() {
    vector<ll> isprime(N, 1), prime;

    for (ll i = 2; i < N; i++) {
        if(isprime[i]) prime.push_back(i);
        for (int j = 0; i * prime[j] < N; j++) {
            isprime[i * prime[j]] = 0;
            if (i % prime[j] == 0) break;
         } 
    }
    for (int i = 0; i < prime.size(); i++) {
        myset.insert(prime[i] * prime[i]);
        // 1ll * prime[i] * prime[i]
    }

}

int main () {
    ios::sync_with_stdio(0), cin.tie(0);
    ll t, n;
    sol();
    cin >> t;
    while(t--) {
        cin >> n;
        if (myset.find(n) != myset.end()) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}