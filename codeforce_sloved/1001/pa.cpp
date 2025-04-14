#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        string s, ss;
        cin >> s;
        int ans = 0;
        int nex = 1;
        
        for(int i = 0; i < s.size(); i++) {
            ss += '0';
        }
        // cout << ss << '\n';
        while(s != ss) {
            int j;
            for(int i = 0; i < s.size(); i++) {
                if(s[i] == '1' && nex && s != ss) {
                    s[i] = '0';
                    nex = 0;
                    
                } 
                else if(s[i] == '0' && !nex && s != ss) {
                    s[i] = '1';
                    nex = 1;
                    j = i;
                }
            }
            if(nex) s[j] = '0';
            ans++;
            nex = 1;
        }
        cout << ans << '\n';
    }
    return 0;
}
/*
01100101011101
00110010101110
00011001010110
00001100101010
00000110010100
00000011001000

*/



