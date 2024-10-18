// 質數篩 --> 線性篩 (標記合數的最小質因數)
#include<bits/stdc++.h>

using namespace std;

void sol() {
    int n;
    cin >> n;
    vector<int> factor, prime;
    factor.resize(n + 1, 0);

    for (int i = 2; i <= n; i++) {
        if (!factor[i]) prime.push_back(i);
        for (int j = 0; i * prime[j] <= n; j++) {
            factor[i * prime[j]] = prime[j];
            if (i % prime[j] == 0) break;
        }
    }
    for (int i = 0; i < prime.size(); i++) {
        cout << prime[i] << '\n';
    }
}

int main(void) {
    sol();
    return 0;
}


//公司與非公司的缺點，及一些專有名詞，講義涵蓋的章節