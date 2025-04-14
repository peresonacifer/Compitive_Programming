#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    bool change = true;

    string s, ans;
    cin >> s;
    int ca = 0;
    for(size_t i = 0; i < s.size(); i++) {
        if(i == 0) {
            if(s[i] < 'a') {
                ca = 1;
                ans += tolower(s[i]);
            }
            else ans += toupper(s[i]);
        }
        else {
            if(ca) {
                if(s[i] < 'a') ans += tolower(s[i]); 
                else {
                    change = false;
                    break;
                }
            }
            else {
                if(s[i] > 'Z') {
                    change = false;
                    break;
                }
                else ans += tolower(s[i]);
            }
        }
    }

    cout << ((change) ? ans : s) << '\n';
    return 0;
}