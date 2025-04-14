#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        if(b >= -1 * a * c && b <= a * c) {
            if(b < 0) {
                if((-1 * b) % c) cout <<  - 1 * b / c + 1 << '\n';
                else cout << -1 * b / c << '\n';
            }

            else {
                if(b % c) cout << b /c + 1 << '\n';
                else cout << b/ c << '\n';
            } 
        }
        else cout << -1 << '\n';
    }
    return 0;   
}

