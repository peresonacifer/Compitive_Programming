#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        if(!((x - 1) % 3)) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }

    return 0;
}

