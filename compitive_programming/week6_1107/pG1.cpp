#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct gd
{
    int t;
    int dl;
};

void sol() {
    int N;
    cin >> N;
    vector<gd> vtr(N);

    for(int i = 0; i < N; i++) {
        cin >> vtr[i].t >> vtr[i].dl;
    }

    sort(vtr.begin(), vtr.end(), [](const auto &a, const auto &b) {
        return a.dl < b.dl ; 
    });

    ll sum = 0;
    for(auto i = vtr.begin(); i != vtr.end(); i++) {
        if((sum + (*i).t) <= (*i).dl) {
            sum += (*i).t;
        }
        else {
            cout << "No";
            return;
        }
    }

    cout << "Yes";
    return;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    sol();
    return 0;
}