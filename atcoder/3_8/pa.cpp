#include<bits/stdc++.h>
using namespace std;
bool cmp(const int &a, const int &b) {
    
    return a > b;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    int ar[n], br[m];
    for(int i = 0; i < n; i++) cin >> ar[i];
    for(int i = 0; i < m; i++) cin >> br[i];
    sort(ar, ar + n, cmp);
    sort(br, br + m, cmp);
    long long Max1 = 0, Max2 = 0, pos = -1;
    for(int i = 0; i < n; i++) {
        if(ar[i] > 0) {
            Max1 += ar[i];
            pos = i;
        }
    }
    for(int i = 0; i < m; i++) {
        if(br[i] > 0 && i <= pos) Max1 += br[i];
        if((Max2 + br[i] + ar[i] ) > Max2 && i < n) {
            Max2 = Max2 + br[i] + ar[i];
        }
        else break;
    }    
    // cout << "1:"  << Max1 << "2:" << Max2;
    cout << max(Max1, Max2) << '\n';
    return 0;
}