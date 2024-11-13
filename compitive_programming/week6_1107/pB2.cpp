#include<bits/stdc++.h>
using namespace std;
using ll = long long;


struct tp {
    int start;
    int end;
};

bool comp(const tp &a, const tp &b) {
    return a.start < b.start;
}

tp vt[101];

void sol() {
    int n, m, d = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> vt[i].start >> vt[i].end;
    }
    sort(vt, vt + n, comp); //iterator accepted

    for(int i = 0; i < n; i++) {
        if(vt[i].start <= d) {
            d = max(d, vt[i].end);
        }
        else break;
    }
    
    cout << (d == m ? "YES" : "NO");
    return;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    sol();
    return 0;
}
