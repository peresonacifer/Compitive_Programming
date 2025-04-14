#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int ar[n][n];
        memset(ar, 0 , sizeof(ar));
        if(n == 1) {
            cin >> ar[0][0];
            cout << ar[0][0] << '\n';
            continue;
        }
        ll S = 0;
        for(int i = 0; i < n; i++) {
            cin >> ar[0][i];
            S += ar[0][i];
        }
        ll s = 0;
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < n - i; j++) {
                ar[i][j] = ar[i - 1][j + 1] - ar[i - 1][j];
                s += ar[i][j];
            }
            S = max(s, 1ll * -1 * s);
        }

        cout << S << '\n';
    }
    return 0;
}
/*
01100101011101
00110010101110
00011001010110
00001100101010
00000110010100
00000011001000

*/



