#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    map<int, int> mp;
    string s = "01032025";
    for(int i = 0; i < s.size(); i++) {
        mp[s[i] - '0']++;
    }
    
    int n, t;
    cin >> t;

    while(t--) {
        map<int, int> mpp(mp);
        cin >> n;
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            if(mpp.find(x) != mpp.end()) {
                mpp[x]--;
                if(!mpp[x]) mpp.erase(mpp.find(x));
            }
            if(mpp.empty() && !ans) ans = i;
        }
        cout << ans << '\n';
    }
    return 0;
}