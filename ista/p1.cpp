#include<bits/stdc++.h>
using namespace std;
#define ll long long

void sol() {
    int n;  // 使用整數類型更合適
    cin >> n;
    double ans = 0;

    if(n >= 30) ans =  n * 50 * 0.7;
    else if(n >= 11) ans = n * 50* 0.7;
    else ans = n * 50;

    // 使用 round 函數先四捨五入，再轉換為整數
    cout << (int)round(ans) << '\n';  // 進行四捨五入後，輸出整數
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;  // 讀取測試案例數
    while(t--) {
        sol();
    }
    return 0;
}
