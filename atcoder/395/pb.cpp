#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    char ar[n + 1][n + 1];
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n + 1 - i; j++) {
            for(int k = i; k <= n + 1 - i; k++) {
                if(i % 2) ar[j][k] = '#';
                else ar[j][k] = '.';
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << ar[i][j];
        }
        cout << '\n';
    }

    return 0;   
}

