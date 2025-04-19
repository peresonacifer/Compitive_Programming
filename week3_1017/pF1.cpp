#include<bits/stdc++.h>
using namespace std;

using ll = long long;

void sol() {
    int n, max = 0;
    cin >> n;
    vector<int> arr(n);
    for (int &i : arr) {
        cin >> i;
        if (i > max) max = i;
    }
    vector<int> factor(max + 1, 0), prime, counts(1e6 + 1, 0);
    // cout << max << '\n';
    factor[0] = factor[1] = 1;

    for (int i = 2; i <= max; i++) {
        if(!factor[i]) {
            prime.push_back(i);
            factor[i] = i;
        }
        for (int j = 0; i * prime[j] <= max; j++) {
            factor[i * prime[j]] = prime[j];
            if (i % prime[j] == 0) break;
            }    
    }
    // for (auto p : factor) cout << p << '\n';
    // for (size_t t = 0; t < factor.size(); t++) cout << t << ':' << factor[t] << '\n';
    // cout << factor[14];
    // map<int, int> mp;

    for (auto it = arr.begin(); it != arr.end(); it++) {
        counts[*it]++;
        for (ll k = factor[*it]; k * k <= *it; k++) {
            // cout << k << '\n';
            if (k * k == *it) {
                counts[k]++;
                
                // t++;
            }
            else { 
                if (*it % k == 0) {
                    counts[k]++;
                    counts[*it / k]++;
                    // t++;
                }
            // cout << k << '\n';
            }
        for (int j = 0; j <= max; j++) cout << counts[j] << " ";    
        cout << '\n';
        }
    }
    // // cout << t;
    for (int i = max; i > 0; i--) {
        if(counts[i] >= 2) {
            cout << i;
            return;
        }
    }
    cout << 1;
    // for (auto p : prime) cout << p << '\n';
    // cout << "*****\n";
}

int main () {
    ios::sync_with_stdio(0), cin.tie(0);
    sol();
    return 0;
}

