#include <bits/stdc++.h>

#define F first
#define S second
#define ALL(x) begin(x), end(x)

using namespace std;
using pii = pair<int, int>;
using ll = long long;

void sol() {
    pii pts[3];
    for (int i = 0; i < 3; i++) {
        cin >> pts[i].F >> pts[i].S;
    }
    for (int i = 0; i < 3; i++) {
        int xx = (pts[i].F - pts[(i + 1)%3].F) * (pts[(i + 1)%3].F - pts[(i + 2)%3].F);
        int yy = (pts[i].S - pts[(i + 1)%3].S) * (pts[(i + 1)%3].S - pts[(i + 2)%3].S);
        if (xx == -yy) {
            cout<< "Wow! It is a right triangle!";
            return;
        }
    }
    cout<< "Sad:( It isn't a right triangle.";
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