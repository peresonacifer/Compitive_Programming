#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, ans = 0;
    cin >> n; 
    int ar[n];
    for(int i = 0; i < n; i++) cin >> ar[i];
        
    if(n <= 2) cout << ans << '\n';
    else {
        for(int i = 0; i < n; i++) {
            if(i > 0 && i < n - 1 && ((ar[i] > ar[i - 1] && ar[i] > ar[i + 1]) || (ar[i] < ar[i - 1] && ar[i] < ar[i + 1]))) {
                ans++;
            }
        }
        cout << ans << '\n';
    }    
    return 0;   
}

