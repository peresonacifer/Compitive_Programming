#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void sol() {
    int n;
    cin >> n;
    set<int> s;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.insert(x);
        // cout << s.size() << " ";
    }
    cout << s.size() << endl;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while(t--) sol();
    return 0;
}