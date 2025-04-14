#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if(s.size() == 1) cout << 1 << '\n';
        for(int i = s.size() - 1; i > 0; --i) {
            if(s[i] == s[i - 1]) {
                cout << 1 << '\n';
                break;
            }
            if(i == 1) cout << s.size() << '\n';
        }
    }
    return 0;   
}

