#include<bits/stdc++.h>

using namespace std;


void sol() {
    int n = 100000000;
    cin >> n;
    bool isprime[n + 1];
    vector<int> prime;
    memset(isprime, 1, sizeof(isprime));
    isprime[0] = isprime[1] = 0;
    for (int i = 2; i <= n; i++) {
        if (isprime[i]) prime.push_back(i);
        for (int j = i; j * i <= n; j++) {
            isprime[i * j] = 0;
        }
    }
    // for (vector<int>::iterator it = prime.begin(); it != prime.end(); ++it ) cout << *it << '\n';
    for (int i = 1; i <= prime.size
}
int main(void) {
    sol();
    return 0;
}