#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> cnt(10, 0);

void bfs(vector<vector<char>>& grid, int n, int m) {
    vector<vector<char>> ori = grid;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] != 0) {
                queue<pair<int, int>> q;
                char tar = grid[i][j];
                cnt[tar - '0']++;
                grid[i][j] = 0;
                q.push({i, j});
                while(!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for(int dx = -1; dx <= 1; dx++) {
                        for(int dy = -1; dy <= 1; dy++) {
                            if(abs(dx) + abs(dy) == 1) { 
                                int nx = x + dx, ny = y + dy;
                                if(nx >= 0 && nx < n && ny >= 0 && ny < m && (grid[nx][ny] == tar || grid[nx][ny] == '*')) {
                                    cnt[tar - '0']++;
                                    grid[nx][ny] = 0;
                                    q.push({nx, ny});
                                }
                            }
                        }
                    }
                }
            }
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    if(ori[i][j] == '*') {
                        grid[i][j] = '*';
                    }
                }
            }
        }
    }
}
/*
7 
10000200300000 
10000200300000 
11110200300000 
100***11300000 
00020044*44400 
00220040333000 
00200000003000 
*/
void sol() {
    int n;
    cin >> n;
    vector<vector<char>> grid(n);
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < s.size(); j++) {
            grid[i].push_back(s[j]);
        }
    }
    bfs(grid, n, grid[0].size());
    vector<pair<int, int>> ans;
    for(int i = 1; i < 10; i++) {
        if(cnt[i] != 0) ans.emplace_back(i, cnt[i]);
    }
    sort(ans.begin(), ans.end(), [](pair<int, int> a, pair<int, int> b) {
        if(a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    });
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i].first << " " << ans[i].second << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    // cin >> t;  
    while(t--) {
        sol();
    }
    return 0;
}