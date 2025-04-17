#include<bits/stdc++.h>
using namespace std;
#define ll long long

void sol() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 1; i < n - 1; i++) {
        vector<int> cur = {v[i - 1], v[i], v[i + 1]};
        sort(cur.begin(), cur.end());
        v[i] = cur[1]; 
    }

    for (int i = 0; i < n; i++) (i != n - 1 ? cout << v[i] << " " : cout << v[i] << "\n");
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    // cin >> t; 
    while(t--) {
        sol();
    }
    return 0;
}