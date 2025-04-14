#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m , k, t;
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        int av = k / n;
        if(k % n) av++;
        if(av % (m - av + 1)) cout << av / (m - av + 1) + 1;
        else cout << av / (m - av + 1);
        cout << '\n';
    }
    return 0;
}