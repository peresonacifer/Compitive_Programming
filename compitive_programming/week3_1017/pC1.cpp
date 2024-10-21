//TLE and MLE :(
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void sol() {
    ll n[10], max = 0;
    set<int> myset;
    int t;
    for (t = 0; t < 10; t++) {
        cin >> n[t];
        if (n[t] > max) max = n[t];
        if (!n[t]) break;
        myset.insert(n[t]);

    }   
    vector<ll> factor(max + 1, 0), prime;
    map<ll, vector<pair<ll, int>>> mymap;
    for (ll i = 2; myset.size() > 0; i++) {
        if(!factor[i]) {
            prime.push_back(i);
            factor[i] = i; 
            if (myset.find(i) != myset.end()) {
                mymap[i].push_back(make_pair(i, 1));
                myset.erase(myset.find(i));
            }
        }  
        for (ll j = 0; i * prime[j] <= max && myset.size() > 0; j++) {
            factor[i * prime[j]] = prime[j];
            if (myset.find(i * prime[j]) != myset.end()) {
                int t = 0;
                for (ll x = i * prime[j]; x != 1; x /= factor[x]) {
                    if (x / factor[x] % factor[x] != 0) {
                        mymap[i * prime[j]].push_back(make_pair(factor[x], t + 1));
                        t = 0;
                    }
                    else t++;
                }
                myset.erase(myset.find(i * prime[j]));
            }
            if (i % prime[j] == 0) break;
        }
    }
    for (int j = 0; j < t; j++) {
        for (auto p : mymap[n[j]]) {
            cout << p.first << '^' << p.second << ' ';
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    sol();
    return 0;
}