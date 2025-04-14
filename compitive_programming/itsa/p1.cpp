#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);    
    int t;
    cin >> t;
    while(t--) {
        string s1, s2, ans;
        cin >> s1 >> s2;
        int carry = 0;
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        for(int i = 0; i < max(s1.size(), s2.size()); i++) {
            int x = 0;
            if(carry) {
                x++;
                carry = 0;
            }
            if(i < s1.size()) x += s1[i] - '0';
            if(i < s2.size()) x += s2[i] - '0';
            ans += x % 10 + '0';
            if(x >= 10) {
                carry = 1;
            }
        }
        if(carry) {
            ans += '1';
        }
        reverse(ans.begin(), ans.end());
        for(int i = 0; i < ans.size(); i++) {
            cout << ans[i];
        }
        cout << '\n';
    }
    return 0;
}