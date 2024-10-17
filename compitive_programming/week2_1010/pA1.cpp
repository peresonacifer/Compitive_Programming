#include <bits/stdc++.h>
#include <cctype>

using namespace std;
using pii = pair<int, int>;
using ll = long long;

void sol() {
    string s;
    cin >> s;
    if (s[0] < 'a') {
        string tmp; 
        tmp += tolower(s[0]);
        for (int i = 1; i < s.size(); i++) {
            if (s[i] < 'a') tmp += tolower(s[i]);
            else {
                cout << s;
                return;
            }
        }
        cout << tmp;
        return;
    }
    else {
        string tmp;
        tmp += toupper(s[0]);
        for (int i = 1; i < s.size(); i++) {
            if (s[i] < 'a') tmp += tolower(s[i]);
            else { 
                cout << s;
                return;
            }
        }
        cout << tmp;
        return;
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int tc = 1;
    //cin >> tc;
    while (tc--) {
        sol();
    }
    return 0;
}