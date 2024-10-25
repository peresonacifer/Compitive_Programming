#include<bits/stdc++.h>
using namespace std;

void sol() {
    
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    while(n != 0) {
        cout << n % 10;
        n -= n % 10;
        n /= 10;
    }
    return 0;
}