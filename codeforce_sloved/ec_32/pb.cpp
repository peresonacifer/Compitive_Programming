#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, ans = 0;
    cin >> n; 
    char ch;
    int ar[4] = {0};
    for(int i = 0; i < n; i++) {
        cin >> ch;
        if(ch == 'U') ar[0]++;
        else if(ch == 'D') ar[1]++;
        else if(ch == 'L') ar[2]++;
        else ar[3]++;
    }
    //cout << 2 * min(ar[2], ar[3]) << " " << 2 * min(ar[0], ar[1]) << '\n';
    ans = 2 * min(ar[2], ar[3]) + 2 * min(ar[0], ar[1]); 
    cout << ans << '\n';
    return 0;   
}

