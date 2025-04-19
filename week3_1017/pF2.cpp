#include<bits/stdc++.h>
using namespace std;

using ll = long long;

void sol() {
    int n, max = 0;
    cin >> n;
    vector<int> arr(n), counts(1e6 + 1, 0);
    for (int &i : arr) {
        cin >> i;
        counts[i]++;
        if (i > max) max = i;
    }
    
    for (int i = max; i > 0; i--) {
        int gcdcounts = 0;
        for (int j = i; j <= max; j += i) {
            gcdcounts += counts[j];
            if (gcdcounts >= 2) {
                cout << i;
                return;
            }
        }
    }
}

int main () {
    ios::sync_with_stdio(0), cin.tie(0);
    sol();
    return 0;
}
