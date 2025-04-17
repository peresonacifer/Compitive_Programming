#include<bits/stdc++.h>
using namespace std;
#define ll long long

void sol() {
    double h, w, o, ch;
    while(1) {
        cin >> h >> w >> o;
        cout << setprecision(2) << fixed;
        cout << w / h * 41.2 << " ";
        double pls;
        cout << setprecision(2) << fixed;
        if(o > 30) {
            int n = (o - 30) / 5;
            pls = n * 0.15;
            cout << h * w / 634.4 + pls << " ";
        }
        else cout << h * w /634.4 << " ";
        cout << setprecision(2) << fixed;
        if(o > 28) {
            int n = (o - 28) / 2;
            pls = n * 0.25;
            cout << w * 0.4 + pls << '\n';
        }
        else cout << w * 0.4 << '\n';
        cin >> ch;
        if(ch == -1) break;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    // cin >> t;  // 讀取測試案例數
    while(t--) {
        sol();
    }
    return 0;
}
