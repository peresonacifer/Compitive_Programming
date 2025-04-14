#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, x, sum = 0, sum2 = 0;
    cin >> n;
    int best = 0;
    for(int i = 0; i < n; i++) {
        cin >> x;
        sum += x;
        if(x == 1) x = -1;
        else x = 1;
        sum2 = max(x, sum2 + x);
        best = max(best, sum2);
    }
    if(best == 0) best = -1;
    cout << sum + best << '\n';

    return 0;
}
