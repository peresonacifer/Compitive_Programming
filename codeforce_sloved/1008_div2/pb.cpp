#include <bits/stdc++.h>
using namespace std;
#define ll long long;
#define pii pair<int, int>

void sol() {
    int n, k;
    cin >> n >> k;
    if(k % 2 == 0) {
        for(int i = 1; i <= n; i++) {
            if(i != n - 1) cout << n - 1<< ' ';
            else cout <<  n << ' ';
        }
    }
    else {
        for(int i = 1; i <= n; i++) {
            if(i != n) cout << n << ' ';
            else cout << n - 1 << ' ';
        }
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--) {
        sol();
    }

    return 0;
}