#include<bits/stdc++.h>
using namespace std;

void sol() {
    int n;
    cin >> n;
    long long a = 0, b = 0;
    long long ans = 0;
    for(int i = 0; i < n; i++) {
        char c;
        cin >> c; 
        if(c == '-') a++;
        else b++;
    }
    int x = a / 2;
    ans = b * (x * (a - x)); 
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        sol();
    }
    return 0;   
}

