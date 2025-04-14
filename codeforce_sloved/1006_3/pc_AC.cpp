#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define all(a) a.begin(), a.end()
const int mod = 1e9 + 7, N = 100007;

void solve() {
    int n, x;
    cin >> n >> x;
    vector <int> a(n);
    int t = 0;
    for (int i = 0; i + 1 < n; ++i) {
        if ((x & i) == i) {
            a[t++] = i;
        } else {
            break;
        }
    }
    if (t == n - 1) {
        a.back() = n - 1;
        if (accumulate(all(a), 0, [&](int i, int j) { return i | j; }) != x) {
            a.back() = x;
        }
    } else {
        while (t < n) {
            a[t++] = x;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " \n"[i + 1 == n];
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}