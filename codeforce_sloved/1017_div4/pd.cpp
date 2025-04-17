#include<bits/stdc++.h>
using namespace std;

void sol() {
    string p,s;
    cin >> p >> s;
    int i, j;
    for(i = 0, j = 0; i < p.size() && j < s.size();) { 
        char c = p[i];
        int t1 = 0, t2 = 0;
        while(i < p.size() && c == p[i]) {i++; t1++;}
        
        while(j < s.size() && c == s[j]) {j++; t2++;}
        if(t1 > t2 || 2 * t1 < t2) {
            cout << "NO\n";
            return;
        }
    }
    if(i < p.size() || j < s.size()) cout << "NO\n";
    else cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        sol();
    }
    return 0;
}