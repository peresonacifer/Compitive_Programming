#include<bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> vtr;
ll ar[500001];

void num() {
    ar[0] = 0;
    ll squre  = 1;
    ll x = 1;
    for(int i = 1; i <= 500000; i++) {
        ar[i] = ar[i - 1] + i;
        if(squre == ar[i]) vtr.push_back(i);
        else if(squre < ar[i]) squre = (++x) * (x); 
    }

}


int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    num();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int x = upper_bound(vtr.begin(), vtr.end(), n) - vtr.begin();
        if(vtr[x - 1] == n) cout << -1 << '\n';
        else {
            int idx = 0;
            bool ch = false;
            for(int i = 1; i <= n; i++) {
                if(ch) {
                    cout << i - 1 << " ";
                    ch = false;
                    continue;
                }
                if(idx <= (x - 1) && vtr[idx] == i) {
                    cout << i + 1 << " ";
                    ch = true;
                    idx++;
                    continue;
                }
                cout << i << " ";
            }
            cout << '\n';
        }
    }

    return 0;
}

