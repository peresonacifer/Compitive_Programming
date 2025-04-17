#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int x, n, m;
        cin >> x >> n >> m;
        int y = x, a = n, b = m;
        while(y > 1 && (n > 1 || m > 0)) {
            if(m) {
                y = (y + 1) / 2;
                m--;
            }
            else {
                y /= 2;
                n--;
            }
        }
        if(n) y /= 2;
        else if(m) y = (y + 1) / 2;
        cout << y << ' ';
        y = x, n = a, m = b;
        while(y > 1 && (n > 0 || m > 1)) {
            if(n) {
                y /= 2;
                n--;
            }
            else {
                y = (y + 1) / 2;
                m--;
            }
        }
        if(n) y /= 2;
        else if(m) y = (y + 1) / 2;
        cout << y << '\n';
    }

    return 0;
}