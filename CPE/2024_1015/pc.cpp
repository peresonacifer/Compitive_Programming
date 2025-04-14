#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    while(1) {
        long long n;
        cin >> n;
        if(n == 0) break;
        long long p = sqrt(n);
        if(p * p == n) cout << "yes" << '\n';
        else cout << "no" << '\n';
    }
    return 0;
}
/*
3
6241
8191
0


*/