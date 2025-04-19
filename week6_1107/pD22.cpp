#include<bits/stdc++.h>
using namespace std;

int main() {
    int m;
    cin >> m;
    //left_and_right
    vector<pair<int,int>> lar;

    // cin left_and_right
    while(1){
        int l, r;
        cin >> l >> r;
        if(l==0 && r==0) break;
        lar.push_back({l, r});
    }

    sort(lar.begin(), lar.end());

    // 把對的pair丟入ans
    vector<pair<int,int>> ans;
    // right_most_index
    int rm=0, idx=0;

    while(rm < m) {
        int now=rm;
        // now_segments
        pair<int,int> nse={0, 0};

        while(idx < lar.size() && lar[idx].first <= rm) {
            if(lar[idx].second > now) {
                now = lar[idx].second;
                nse = lar[idx];
            }
            idx++;
        }

        if(now == rm) {
            cout << "No solution" << '\n';
            return 0;
        }

        // 更新rm
        rm = now;
        ans.push_back(nse);
    }

    cout << ans.size() << '\n';
    for(int i=0; i < ans.size(); i++) {
        cout << ans[i].first << " " << ans[i].second << '\n';
    }

    return 0;
}