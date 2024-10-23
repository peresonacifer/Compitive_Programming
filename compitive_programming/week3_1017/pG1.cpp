#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void sol() {
    int n, num = 1;
    cin >> n;
    set<int> st;
    for (int i = 0; i < n; i++) {
        int d;
        cin >> d;
        if (st.find(d) != st.end()) {
            cout << -1 << '\n';
            return;
        }
        st.insert(d);
    }
    vector<int> vct(st.begin(), st.end());
    ll x = vct[0] * vct[n - 1];
    for (ll i = 2; i <= x; i++) {
        int t = 1;
        while (x % i == 0) {
            x /= i;
            t++;
        }
        num *= t;
    }
    if (num - 2 == n) {
        x = vct[0] * vct[n - 1];
        int i = 0, j = n - 1;
        while (i <= j) {
            if (1ll * vct[i] * vct[j] != x) {
                cout << -1 << '\n';
                return;
            }
            i++;
            j--;
        }
        cout << x << '\n';
    }
    else cout << -1 <<'\n';
} 

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        sol();
    }
    return 0;
}
