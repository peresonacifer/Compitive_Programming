    #include<bits/stdc++.h>
    using namespace std;
    using i64 = long long;
    using u64 = unsigned long long;
    typedef pair<int, int> pii;
    #define rep(i,n) for(i64 i=0; i<i64(n); i++)
    #define push_back pb
    #define all(x) x.begin(), x.end()
    #define sz(x) (int)x.size()
    #define first F
    #define second S
    template<typename A> void chmin(A& l, const A& r){ if(r < l) l = r; }
    template<typename A> void chmax(A& l, const A& r){ if(l < r) l = r; }

    void sol() {
        int n, k; cin >> n >> k;
        vector<int> a(n); rep(i, n) cin >> a[i];
        int t = 0, sum = -1;
        bool ch = true;
        rep(i, n) {
            int x;
            cin >> x;
            if(x == -1) {
                t++; continue;
            }
            else {
                if(sum == -1) sum = x + a[i];
                else if(sum != x + a[i]) {
                    ch = false;
                }
            }
        }   
        if(ch)  {
            sort(all(a));
            if(sum != -1 && (sum < a[n - 1] || sum - a[0] > k)) cout << 0 << '\n';
            else if(sum != -1) cout << 1 << '\n';
            else cout << k - (a[n - 1] - a[0]) + 1 << '\n'; 
        }
        else cout << 0 << '\n';

    }

    int main() {
        ios::sync_with_stdio(false), cin.tie(nullptr);
        int T = 1; 
        cin >> T; 
        rep(i, T) sol();
        return 0;
    }