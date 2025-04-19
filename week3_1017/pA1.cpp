#include<bits/stdc++.h>

using namespace std;


void sol() {
    long long n; 
    long long j;
    cin >> n;

    for (long long i = 1 ; i * i <= n; i++) {
        if(n % i == 0) cout << i << '\n';
        j = i;
    }
    if (j * j == n) j--;

    for (long long k = j; j >= 1; j--) {
        if(n % j == 0) cout << n / j << '\n';
    }
}
int main(void) {
    int a;
    sol();
    return 0;
}