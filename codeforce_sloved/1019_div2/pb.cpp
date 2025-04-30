#include<bits/stdc++.h>
using namespace std;
using ll = long long;


void sol() {
    int n;
    string s;
    cin >> n >> s;
    char c = '0';
    int t = 0;
    int sp = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] != c) {
            t++;
            c = s[i];
            sp++;
        }
        t++;
    }
    if(sp - 1 < 0) sp = 0;
    else sp--;
    cout << t - min(2, sp) << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while(t--) sol();
    return 0;
}