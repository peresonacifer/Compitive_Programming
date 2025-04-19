#include<bits/stdc++.h>
using namespace std;

const int S = 1e5;

vector<pair<int, int>> vtr, ans;

bool comp(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    else return a.second > b.second;
}

bool comp_(const pair<int, int> &a, const pair<int, int> &b) {
    return a.second < b.second;
}

void sol() {
    int m, minC = 0;
    cin >> m;
    for(int i = 0; i < S; i++) {
        int x, y;
        cin >> x >> y;
        if (x == 0 && y == 0) break;
        vtr.push_back({x, y});
    }
    sort(vtr.begin(), vtr.end(), comp);

    int start = m, end = 0;
    for (auto it = vtr.begin(); it != vtr.end() && start > 0; it++) {
        pair<int, int> rep = {0, 0};
        if ((*it).first > m) continue;
        else {
            if ((*it).first <= start && (*it).second >= m) {
                start = (*it).first;
                end = (*it).second;
                ans.clear();
                ans.push_back({(*it).first, (*it).second});
                minC = 1;
            }
            else {
                if(end == 0) break;
                else if((*it).first <= start - 1 && (*it).second >= start) {
                    if((*it).second == start) {
                        start = (*it).first;
                        ans.push_back({(*it).first, (*it).second});
                        minC++;
                    }
                    else{
                        rep = *it;
                    }
                }
                else if((*it).second <= start - 1) {
                    if(rep.first != 0 && rep.second != 0) {
                        start = (*it).first;
                        ans.push_back({(*it).first, (*it).second});
                        minC++;
                        rep = {0, 0};
                        continue;
                    }
                    else break;
                }
            }
        }
    }
    if (start > 0 || end < m) {
        cout << "No solution";
    }
    else {
        cout << minC << '\n';
        sort(ans.begin(), ans.end(), comp_);
        for (auto it = ans.begin(); it != ans.end(); ++it) {
            cout << (*it).first << " " << (*it).second << '\n';
        }
    }
    return;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    sol();
    return 0;
}
