#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        if(n % 2) {
            for(int i = 1; i <= n; i++) {
                cout << (n + 1) - i << (i != n ? ' ' : '\n');
            }
        }
        else cout << -1 << '\n';
    }

    return 0;
}