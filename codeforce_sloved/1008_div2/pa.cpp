#include <bits/stdc++.h>
using namespace std;
#define ll long long;
#define pii pair<int, int>

void sol() {
    int n, x, sum = 0;
    cin >> n >> x;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];        
    }
    if((sum % n == 0 ) && (sum / n == x)) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--) {
        sol();
    }

    return 0;
}