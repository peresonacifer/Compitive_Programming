#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

void sol() {
    int n;
    cin >> n;
    vector<pii> vtr(n);
    for(int i = 0; i < n; i++) {
        cin >> vtr[i].first >> vtr[i].second;
    }
    sort(vtr.begin(), vtr.end(), [](const pii &a, const pii &b) {
        return a.first < b.first;
    });

    ll reward = 0, sum = 0;
    for(auto p : vtr) {
        sum += p.first;
        reward += p.second - sum;
    }
    cout << reward;
    return;
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    sol();
    return 0;
}

