#include<bits/stdc++.h>
using namespace std;
#define ll long long
int cnt;

void bfs(vector<vector<char>>& grid, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == '0') {
                cnt++;
                queue<pair<int, int>> q;
                q.push({i, j});
                while(!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    grid[x][y] = '1'; 
                    for(int dx = -1; dx <= 1; dx++) {
                        for(int dy = -1; dy <= 1; dy++) {
                            if(abs(dx) + abs(dy) == 1) { 
                                int nx = x + dx, ny = y + dy;
                                if(nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == '0') {
                                    q.push({nx, ny});
                                    grid[nx][ny] = '1';
                                }
                            }
                        }
                    }
                }
            }
        }
    }

}
/*
10
1111000111
0000000111
1100001101
1100011001 
0000101111
0000101000 
0010011000
0101000000
0010000000
0000011111
*/
void sol() {
    int n;
    cin >> n;
    cnt = 0;
    vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    } 
    bfs(grid, n);
    cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    // cin >> t;  // 讀取測試案例數
    while(t--) {
        sol();
    }
    return 0;
}