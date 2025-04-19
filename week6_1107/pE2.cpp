#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

vector<int> ans;
int  bd[20001];

void sol() {
    int K, N;
    cin >> K >> N;
    
    memset(bd, 0, sizeof(bd));
    vector<pii> vtr;
    
    for(int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        if(x > y) swap(x, y);
        if((y - x) < K - 1) {
            for(int i = x; i <= y; i++) {
                if(!bd[i + 10000]) {
                    bd[i + 10000] = 1;
                    ans.push_back(i);
                }
            }
        }
        else {
            vtr.push_back({x, y});  
        }
    }

    sort(vtr.begin(), vtr.end(), [](const pii &a, const pii &b) {
        return a.second < b.second || ((a.second == b.second) && a.first < b.first);
    });

    for(auto it = vtr.begin(); it != vtr.end(); ++it) {
        int adp = 0, start = (*it).first, end = (*it).second;

        for(int i = start; i <= end && adp < K; i++) {
            adp += bd[i + 10000];
        }

        if(adp >= K) continue;;

        for(int j = end; j >= start && adp < K; --j) {
            if(!bd[j + 10000]) {
                bd[j + 10000] = 1;
                ans.push_back(j);
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
