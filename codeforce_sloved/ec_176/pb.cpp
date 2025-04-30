#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t, n, k;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        vector<int> v(n);
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }        
        if(k == 1) {
            if(v[0] < v[n - 1]) swap(v[0], v[n - 1]);
            ans += v[0];
            for(int i = 1; i < n - 1; i++) {
                if(v[i] > v[n - 1]) swap(v[i], v[n - 1]);
            }
            ans += v[n - 1];
        }
        else {
            sort(v.begin(), v.end());
            for(int i = n - 1; n - i <= k + 1; i--) {
                ans += v[i];
            }
        }
        cout << ans << '\n';
    }
    
    return 0;
}
