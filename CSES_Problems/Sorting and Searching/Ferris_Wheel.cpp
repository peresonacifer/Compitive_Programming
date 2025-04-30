#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, x, ans = 0;
    cin >> n >> x;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    int l = 0, r = n - 1;
    while(r >= l) {
        if(l == r) {
            ans++;
            break;
        }
        if(v[r] + v[l] <= x) {
            r--; l++;
        }
        else {
            r--;
        }
        ans++;
    }

    cout << ans << '\n';
    return 0;
}