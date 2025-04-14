#include <bits/stdc++.h>
using namespace std;
#define ll long long

void sol() {
    ll ans = 0;
    
    string s, s1;
    while (getline(cin, s)) {
        stringstream ss(s);
        while (ss >> s1) {
            string s2 = "";
            for (int i = 0; i < s1.size(); i++) {
                if (isdigit(s1[i])) s2 += s1[i]; 
                else {
                    if (!s2.empty()) {
                    reverse(s2.begin(), s2.end());
                    stringstream sss(s2);
                    ll x;
                    sss >> x;
                    ans += x;
                    s2 = "";
                    } 
                }
            }
            if (!s2.empty()) {
                reverse(s2.begin(), s2.end());
                stringstream sss(s2);
                ll x;
                sss >> x;
                ans += x;
                s2 = "";
            } 
        }
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    sol();
    return 0;
}
