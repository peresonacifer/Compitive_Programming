#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, t, sum = 0, ans = 0;
    cin >> n >> t;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    int x = 0;
    for(int i = 0, j = 0; i < n; i++) {
        sum += a[i];
        x++;
        while(sum > t) {
            sum -= a[j++];
            x--;
        }
        ans = max(ans, x);
    }
    cout << ans << '\n';
    return 0;
}