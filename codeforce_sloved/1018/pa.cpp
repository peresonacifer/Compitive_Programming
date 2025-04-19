#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int min = 0, max = 0;
        vector<int> ans(n);
        ans[0] = 0;
        for(int i = 0; i < n - 1; i++) {
            if(s[i] == '<') {
                ans[i + 1] = --min;
            }
            else {
                ans[i + 1] = ++max;
            }
        }
        for(int i = 0; i < n; i++) {
            ans[i] += -1 * min + 1;
            cout << ans[i] << (i == n - 1 ? '\n' : ' ');
        }
        
        
    }
    return 0;
}
