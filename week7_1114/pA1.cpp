#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int ans = 0;

void sol() {
    int n;
    ll dif;
    cin >> n >> dif;
    ll ar[n + 1]; 
    vector<ll> sum(n + 1);
    sum[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> ar[i];
        sum[i] = sum[i - 1] + ar[i];
    }
    set<pair<vector<ll>::iterator, vector<ll>::iterator>> ans;

    for(auto i = sum.begin(); i != sum.end(); i++) {  
        // if(dif == 0 && i == sum.begin()) continue;
        vector<ll>::iterator it = find(i + 1, sum.end(), *i + dif);
        while(it != sum.end()) {
            if(ans.find({i, it}) == ans.end()) {
                ans.insert({i, it});
            }
            it = find(it + 1, sum.end(), *i + dif);
        }
    }
    cout << ans.size() << '\n';
    return;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    sol();
    return 0;
}