#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        string s = "1";
        int n, d;
        cin >> n >> d;
        if(n >= 3 || !(d % 3)) s += " 3";

        if(d == 5) s += " 5";

        if(d == 7 || n >= 3) s += " 7";

        if(n >= 6 || d == 9 || !(d % 3) && n >= 3) s += " 9";

        cout << s << '\n';
    }

    return 0;   
}

