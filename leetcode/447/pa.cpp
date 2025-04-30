#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
            unordered_map<int, vector<int>> rowx, coly;
            for(const auto& b: buildings) {
                int x = b[0], y = b[1];
                rowx[y].push_back(x);
                coly[x].push_back(y);
            }
        
            for(auto& [_, vtr] : rowx) {
                sort(vtr.begin(), vtr.end());
            }
            for(auto& [_, vtr] : coly) {
                sort(vtr.begin(), vtr.end());
            }
            int ans = 0;
            for(const auto& b: buildings) {
                int x = b[0], y = b[1];
                bool l = lower_bound(rowx[y].begin(), rowx[y].end(), x) != rowx[y].begin();
                bool r = upper_bound(rowx[y].begin(), rowx[y].end(), x) != rowx[y].end();
                bool u = lower_bound(coly[x].begin(), coly[x].end(), y) != coly[x].begin();
                bool d = upper_bound(coly[x].begin(), coly[x].end(), y) != coly[x].end();
                if(l && r && u && d) ans++;
            }
            cout << ans << '\n';
    }
};  