#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t,  n, k ;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        int cnt = 0;
        if(n % 2)  {
            n -= k;
            cnt++;
        }
        if(n == 0) {
            cout << cnt << '\n';
            continue;
        }
        k = min(n, k - 1);
        if(n % k == 0) cnt += n / k;
        else cnt += n/k + 1;
        cout << cnt << '\n';
    }
    
    return 0;
}
