#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    unordered_map<int, int> mp;
    int n;
    cin >> n;
    int x;
    for(int i = 0; i < n; i++) {
        cin >> x;
        mp[x]++;
    }
    int ans = 0;
    for(auto x: mp) {
        if(x.second < x.first) ans += x.second;
        else ans += x.second - x.first;
    }
    cout << ans << '\n';
    return 0;
}