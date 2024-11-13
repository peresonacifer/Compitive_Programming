#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

vector<int> ans;
int ph[20001], bd[20001];

void sol() {
    int K, N;
    cin >> K >> N;
    
    memset(ph, 0, sizeof(ph));
    memset(bd, 0, sizeof(bd));
    vector<pii> vtr;
    
    for(int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        if(x > y) swap(x, y);
        if((y - x) <= K - 1) {
            for(int j = x; j <= y; j++) {
                if(!bd[i + 10000]) {
                    bd[i + 10000] = 1;
                    ans.push_back(i);
                }
            }
        }
        else {
            for(int j = x; j <= y; j++) {
                ph[j + 10000]++;
            }
            vtr.push_back({x, y});  
        }
    }

    sort(vtr.begin(), vtr.end(), [](const pii &a, const pii &b) {
        return (a.second - a.first) < (b.second - b.first) || ((a.second - a.first) == (b.second - b.first) && a.first < b.first);
    });

    for(auto it = vtr.begin(); it != vtr.end(); ++it) {
        int adp = 0;
        vector<pii> rep_ph;
        for(int i = (*it).first; i <= (*it).second; i++) {
            adp += bd[i + 10000];
            if(!bd[i + 10000]) {
                rep_ph.push_back({i + 10000, ph[i + 10000]});
            }
        }

        if(adp < K) {
            sort(rep_ph.begin(), rep_ph.end(), [](const pii &a, const pii &b) {
                return a.second > b.second || (a.second == b.second && a.first > b.first);
            });

            for(auto ip = rep_ph.begin(); adp < K && ip != rep_ph.end(); ++ip) {
                bd[(*ip).first] = 1;
                ans.push_back((*ip).first - 10000);
                adp++;
            }
        }
    }

    cout << ans.size() << '\n';
    sort(ans.begin(), ans.end());
    for(auto p : ans) {
        cout << p << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    sol();
    return 0;
}
