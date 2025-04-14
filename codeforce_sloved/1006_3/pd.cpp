#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t, cnt, pos1, pos2;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];
        array<int, 3> ans = {0, 0, 0};
        for(int i = 0; i < n; i++) {
            int cnt = 0;            
            for(int j = i; j < n ; j++) {
                cnt += v[j] < v[i];
                cnt -= v[j] > v[i];
                ans = max(ans, {cnt, i, j});
            }
        }
        cout << ans[1] + 1 << " " << ans[2] + 1 << '\n';
    }
    return 0;   
}
