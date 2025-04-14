#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        s.replace(s.size() - 2, 2, "i");
        cout << s << '\n';
    }
    return 0;   
}

