#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t, n;
    cin >> t;
    
    while(t--) {
        vector<int> ans;
        ans.push_back(0);
        cin >> n;
        
        for(int i = 1; i * i <= n; i++) {
            if(i == n / i || i > n / i)  {
                ans.push_back(i);   
                break;
            }
            ans.push_back(i);
            ans.push_back(n / i);
            
        }
        sort(ans.begin(), ans.end());
        cout << ans.size() << '\n';
        for(auto x: ans) cout << x << " ";
        cout << '\n';
    }
    return 0;
}