#include<bits/stdc++.h>
using namespace std;
#define ll long long
//151515
// 3 3 3 3 3 3 3 100
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, t;
    cin >> t;
    while(t--) {
        cin >> n;
        vector<int> ar(n);
        for(int i = 0; i <n; i++) {
            cin >> ar[i];
        }
        int ans = n;
        sort(ar.begin(), ar.end());
        for(int i = 0, j = 0; i < n; i++) {
            while(j + 1 < i && ar[j] + ar[j + 1] <= ar[i]) {
                j++;
            }
            ans = min(ans, n - (i - j + 1));
        }
        cout << ans << '\n';        
    }
    return 0;
}