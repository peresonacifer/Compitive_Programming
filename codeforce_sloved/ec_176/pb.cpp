#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t,  n, k ;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        vector<long long> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];
        long long m = 0;
        int d = n / (k +1);
        for(int i = 0; i < n; i++) {
            int t = 1, y = 0;
            long long x = 0;
            for(int a = 1; a < d; a++) {
                for(int j = i; j < n && t < k + 1; t++, j += d) {
                    x += v[j];
                    y = max(i, n - 1 - i);
                }
                if(y == i)
            }
            
        }
        cout << m << '\n';
    }
    
    return 0;
}
