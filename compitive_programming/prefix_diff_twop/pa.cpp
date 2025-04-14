#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, a;
    map<ll, ll> mp;
    ll sum = 0, x, cnt = 0;
    cin >> n >> x;
    mp[0] = 1;
    for(int i = 0; i < n; i++) {
        cin >> a;
        sum += a;
        
        if(mp.find(sum - x) != mp.end()) {
            cnt += mp[sum - x];
        }
        mp[sum]++;
    }
    cout << cnt << '\n';
    return 0;
}