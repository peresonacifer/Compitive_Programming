//uva10273
#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<int>> cnt(n);
        for(int i = 0; i < n; i++) {
            int T;
            cin >> T;
            vector<int> v(T);
            for(auto &x : v) cin >> x;
            cnt[i] = v;
        }
        int lastn = n, lastd, vis[n] = {0};
        
        for(int d = 0;; d++) {
            int mint = 0x7fffffff, pos = -1;
            for(int i = 0; i < n; i++) {
                if(vis[i]) continue;
                int cur_n = cnt[i][d % cnt[i].size()];
                if(cur_n < mint) {
                    mint = cur_n;
                    pos = i;
                }
                else if(cur_n == mint) pos = -1;
            }
            if(pos != -1) {
                lastn--;
                vis[pos] = 1;
                lastd = d;
            }
            if(lastn == 0 || d - lastd >= 1000) break;
        }
        if(lastn == n) lastd = -1;
        cout << lastn << " " << lastd + 1 << '\n';
    }   
    return 0;
}

/*
1
4
4 7 1 2 9 
1 2
2 7 1
1 2

*/
