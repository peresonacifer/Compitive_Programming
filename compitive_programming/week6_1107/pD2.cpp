#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using  pii = pair<int, int>;

const int S = 1e5;
vector<pii> mset, ans;

void sol() {
    int m;
    cin >> m;
    for(int i = 0; i < S; i++) {
        int x, y;
        cin >> x >> y;
        if(x == 0 && y == 0) break;
        mset.push_back({x, y});      
    }
    
    sort(mset.begin(), mset.end(), [](const pii &a, const pii &b) {
        return a.first < b.first || ((a.first == b.first) && a.second > b.second);
    });

    int end = 0, j = 0;
    while(end < m) {
        int cur_end = end, cur_start;

        while(j < mset.size() && mset[j].first <= end) {
            if (mset[j].second > cur_end) {
                cur_end = mset[j].second;
                cur_start = mset[j].first;
            }
            j++;
        }

        if(cur_end == end) {
            cout << "No solution\n";
            return;
        }

        ans.push_back({cur_start, cur_end});
        end = cur_end;
    }

    cout << ans.size() << "\n";
    for(const auto &p : ans) {
        cout << p.first << " " << p.second << '\n';
    }
    return ;   
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    sol();
    return 0;
}