#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t, x, y;
    cin >> t;
    while(t--) {
        cin >> x;
        for(int i = 1; i <= 30; i++) {
            y = (1 << i) - 1;
            if(y >= x) {
                cout << -1 << '\n';
                break;
            }
            int z = x ^ y;
            if((z != (x + y)) && (z != (x - y))) {
                cout << y << '\n';
                break;
            } 
        }
    }
    return 0;
}