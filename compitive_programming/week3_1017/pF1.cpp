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
    vector<int> factor(max + 1, 0), prime;
    factor[0] = factor[1] = 1;

    for (int i = 2; i <= max; i++) {
        if(!factor[i]) prime.push_back(i);
        for (int j = 0; j < prime.size() && i * prime[j] <= max; j++) {
            if(!factor[i]) factor[i * prime[j]] = i;
            else {
                if (factor[i] > prime[j]) factor[i * prime[j]] = factor[i];
                else factor[i * prime[j]] = prime[j];
            }
        }
        if(!factor[i]) factor[i] = i;
    }
    // for (size_t t = 0; t < factor.size(); t++) cout << t << ':' << factor[t] << '\n';
    // cout << factor[14];
    map<int, int> mp;
    for (auto it = arr.begin(); it != arr.end(); it++) {
        // cout << *it << '\n';
        int f = 1;
        for (int x = *it; x != f; x /= factor[x])  {
            mp[x]++;
            if (x == factor[x]) break;
            if (f == factor[x]) continue;
            mp[factor[x]]++;
            f = factor[x];
        }
        // cout << factor[*it] << '\n';
    }
    for (auto it = mp.rbegin(); it != mp.rend(); it++) {
        if (it -> second >= 2) {
            cout << it -> first;
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

