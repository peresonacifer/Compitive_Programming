#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    bool isprime = true;
    if(n == 1 && k == 1) {
        cout << "No\n";
        return;
    }
    if(n == 1) {
        while(--k) {
            n = n * 10 + 1;
        }
        for(int i = 2; i * i <= n; i++) {
            if(n % i == 0) {
                isprime = false;
                break;
            }
        }
        if(isprime) cout << "Yes\n";
        else cout << "No\n";
        return;
    }
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            isprime = false;
            break;
        }
    }
    if(isprime && k == 1) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }    
    return 0;
}