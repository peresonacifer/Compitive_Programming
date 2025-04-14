#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n, x;
        cin >> n >> x;
        int M;
        int y = x, a = 1;
        while((y | 0) % 2 != 0) {
            y = y >> 1;
           // cout << y;
            a *= 2;
        }
        //cout << "x: " << x << '\n';
        int cur = 0;
        for(int i = 0; i < n; i++) {
            if(a > i)  {
                if(i == n - 1 && i != x) {
                    if((cur | i) == x) cout << i;
                    else cout << x ;
                }
                else cout << i << " ";
                cur = (cur | i);
            }
            else cout << x << " ";
        }
        cout << '\n';
    }
    return 0;
}

