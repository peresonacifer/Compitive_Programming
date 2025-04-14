#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int ar[n], br[200001];
        memset(br, 0, sizeof(br));
        for(int i = 0; i < n; i++) {
            cin >> ar[i];
            br[ar[i]]++;
        }
        int l = -1, r = -1;
        for(int i = 0; i < n; i++) {
            int _l = -1, _r = -1;
            if(br[ar[i]] <= 1) {
                _l = i, _r = i;
                while(i + 1 < n && br[ar[++i]] <= 1) _r++;
                i = _r;
            }
            if(_l != -1 && (_r - _l >= r - l)) l = _l, r = _r;
        }
        if(l == -1 && r == -1) cout << 0 << '\n';
        else cout << l + 1 << " " << r + 1 << '\n'; 
    }
    return 0;
}