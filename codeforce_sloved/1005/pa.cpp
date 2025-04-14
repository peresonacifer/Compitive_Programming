#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ans = 0;
        int i = n - 1;
        while(i > -1) {
            if(s[i] == '1') {
                ans++;
                while(i > -1 && s[i] == '1') i--;
            }            
            if (s[i] == '0'){
                if(i > 0 && s[i - 1] == '1') ans += 2;
                while(i > 0 && s[i - 1] == '1') i--;
            }
            i--;
        }
        cout << ans << '\n';
    }
    return 0;
}