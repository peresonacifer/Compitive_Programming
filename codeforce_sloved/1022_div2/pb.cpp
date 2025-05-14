#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
typedef pair<int, int> pii;
#define rep(i,n) for(i64 i=0; i<i64(n); i++)
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define F first
#define S second
template<typename A> void chmin(A& l, const A& r){ if(r < l) l = r; }
template<typename A> void chmax(A& l, const A& r){ if(l < r) l = r; }

int n, m;
vector<int> c; 
vector<vector<int>> z;
int ans = INT_MAX;

void dfs(int pos, vector<int>& vis, int cost) {
    if (pos == n) {
        for (int i = 0; i < m; i++) {
            if (vis[i] < 2) return;
        }
        ans = min(ans, cost);
        return;
    }

    for (int k = 0; k <= 5 ; k++) {
        for (int i = 0; i < z[pos].size(); i++) {
            int animal = z[pos][i];
            vis[animal] += k;
        }
        dfs(pos + 1, vis, cost + k * c[pos]);
        for (int i = 0; i < z[pos].size(); i++) {
            int animal = z[pos][i];
            vis[animal] -= k;
        }
    }
}

void sol() {
    cin >> n >> m;
    c.resize(n);
    z.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    for (int i = 0; i < m; i++) {
        int K;
        cin >> K;
        for (int j = 0; j < K; j++) {
            int zoo;
            cin >> zoo;
            z[zoo - 1].push_back(i);
        }
    }

    vector<int> vis(m, 0);
    dfs(0, vis, 0);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while(t--) sol(); 
    return 0;
}
