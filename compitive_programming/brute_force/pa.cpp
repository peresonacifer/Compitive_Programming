#include <bits/stdc++.h>
using namespace std;

// xy = (x + y) * k x = yk / y - k
// 13 14    14 * 13 *12
// 14*6  * 84 6

// y = 20 g 4 x 60
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int k;
    while(cin >> k) {
        int t = 0;
        vector<pair<int, int>> v;
        for(int i = k + 1; i <= 2 * k; i++) {
            if((i* k % (i - k)) == 0) {
                v.push_back({i * k / (i - k), i});
                t++;
            }
        }
        if(t) cout << t << '\n';
        for(int i = 0; i < t; i++) {
            cout << "1/"<< k <<" = " << "1/" << v[i].first << " + " << "1/" << v[i].second << '\n';
        }
    }
    return 0;
}