#include<bits/stdc++.h>
using namespace std;

void sol() {
    int n, m;

    cin >> n >> m;
    vector<vector<int>> vtr(n, vector<int>(m));
    vector<int> cnt(n * m), p(n * m);    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> vtr[i][j];
            vtr[i][j]--;
            cnt[vtr[i][j]] = 1;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i + 1 < n && vtr[i][j] == vtr[i + 1][j]) p[vtr[i][j]] = 1;
            if(j + 1 < m && vtr[i][j] == vtr[i][j + 1]) p[vtr[i][j]] = 1;
        }
    }

    int x = accumulate(cnt.begin(), cnt.end(), 0);
    int y = accumulate(p.begin(), p.end(), 0);

    cout << (x + y - (y ? 2 : 1)) << '\n';

}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int t;
    cin >> t;

    while(t--) {
        sol();
    }

    return 0;
}