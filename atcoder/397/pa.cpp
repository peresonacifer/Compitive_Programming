#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    if(n % 2) {
        for(int i = 0; i < n; i++) {
            if(i == n / 2 ) cout << '='; 
            else cout << '-';
        }
    }
    else {
        for(int i = 0; i < n; i++) {
            if(i == n / 2 || i == (n /2 - 1)) cout << '='; 
            else cout << '-';
        }
    }
    cout << '\n';
    return 0;
}
