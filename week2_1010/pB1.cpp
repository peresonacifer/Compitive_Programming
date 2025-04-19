#include <bits/stdc++.h>
#include <cctype>


#define F first
#define S second

using namespace std;
using pii = pair<string, int>;
using ll = long long;

void sol() {
    pii mh[1000], ft[2];
    for (int i = 0; i < 2; i++) ft[i] = make_pair("None", 0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> mh[i].F >> mh[i].S;
        if (mh[i].S > ft[1].S) { 
            ft[1] = {mh[i].F, mh[i].S};
            if (ft[1].S > ft[0].S) swap(ft[1], ft[0]);
        }
    }
    std :: cout << ft[1].F;
    return;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int tc = 1;
    //cin >> tc;
    while (tc--) {
        sol();
    }
    return 0;
}