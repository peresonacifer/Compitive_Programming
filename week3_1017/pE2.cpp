#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void generate_primes(vector<int>& primes, int limit) {
    vector<bool> is_prime(limit + 1, true);
    is_prime[0] = is_prime[1] = false;
    
    for (int i = 2; i * i <= limit; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= limit; j += i) {
                is_prime[j] = false;
            }
        }
    }
    
    for (int i = 2; i <= limit; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
}

void count_similar_numbers(ll N) {
    vector<int> primes;
    generate_primes(primes, 1e6); // 生成質數直到 1e6

    ll count = 0;
    int prime_size = primes.size();
    
    // 計算所有形如 k = p * q^3 的數字
    for (int i = 0; i < prime_size; i++) {
        ll q3 = 1LL * primes[i] * primes[i] * primes[i]; // q^3
        if (q3 > N) break; // 如果 q^3 已經大於 N，直接跳出
        for (int j = i + 1; j < prime_size; j++) { // 確保 p < q
            ll k = 1LL * primes[i] * q3; // k = p * q^3
            if (k <= N) {
                count++;
            } else {
                break; // 若 k 超過 N，後面的 q 也會更大，無需繼續
            }
        }
    }
    
    cout << count << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll N;
    cin >> N;
    count_similar_numbers(N);
    return 0;
}
