#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

struct ord {
    ll time;
    ll find;
    int idx;
    //equal to
    //ll time. find;
    //int idx;
    //another way
    //pii<ll, ll> time_find; --> time_find.first, time_find.second
    //int idx;
};


int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    while(cin >> n && n != 0) {
        // vector<pair<pii, int>> vt;
        vector<ord> order(n);

        for(int i = 0; i < n; i++) {
            // ll x, y;
            // cin >> x, y;
            // vt.push_back({{x, y}, i + 1});
            cin >> order[i].time >> order[i].find;
            order[i].idx = i + 1;
        }

        sort(order.begin(), order.end(), [](const ord &a, const ord &b) {
            return a.find * b.time > a.time * b.find || (a.find * b.time == a.time * b.find) && a.idx < b.idx;
        });

        for(auto p : order) {
            cout << p.idx << " \n"[p.idx == (*(order.end() - 1)).idx] ;
        }
        // cout << '\n';
    }

    return 0;
}