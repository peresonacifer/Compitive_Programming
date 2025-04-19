#include<bits/stdc++.h>
using ll = long long;
using namespace std;

void sol() {
    int n;
    cin >> n;
    int cnt[4] = {0};
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        for(int j = x + 1; j < 4; j++) {
            ans += cnt[j];
        }
        cnt[x]++;
    }

    cout << ans << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    sol();
    return 0;
}