#include<bits/stdc++.h>
using namespace std;

using ll = long long;

void sol(ll N) {
    ll sum = 0;
    vector<ll> isprime(1e6 + 1, 1), prime;

    for (ll i = 2; i * i * i * 2 <= N; i++) {
        if(isprime[i]) prime.push_back(i);
        for (int j = 0; i * prime[j] <= 1e6; j++) {
            isprime[i * prime[j]] = 0;
            if (i % prime[j] == 0) break;
         } 
    }
    for (int q = prime.size() - 1; q > 0; q--) {
        for (int p = 0; p < q; p++) {
            if (prime[q] * prime[q] * prime[q] <= N / prime[p]) sum++;
            else break;
        }
    }
    cout << sum << '\n';
}

int main () {
    ios::sync_with_stdio(0), cin.tie(0);
    ll N;
    cin >> N;
    sol(N);
    return 0;
}