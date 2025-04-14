#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for(auto &x: a) cin >> x;
        if(n == k) {
            int ans = 1;
            for(int i = 1; i < n; i += 2) {
                if(a[i] == ans) ans++;
                else break;;
            }
            cout << ans << '\n';
        }
        else {
            int ans = 2;
            for(int i = 1; i <= n - k + 1; i++) {
                if(a[i] != 1) {
                    ans = 1;
                    break;
                }
            }
            cout << ans << '\n';
        }
    }
    return 0;
}
/*
4
3 2
1 1 1
8 8
1 1 2 2 3 3 4 4
5 4
1 1 1 2 2
5 4
1 1 1000000000 2 2
*/



