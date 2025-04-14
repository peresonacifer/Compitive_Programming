#include<bits/stdc++.h>
using namespace std;
void sol() {
    int n, q;
    cin >> n >> q;
    int a[n], m;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> m;
    a[0] = min(a[0], m - a[0]);

    for(int i = 1; i < n; i++) {
        if(a[i] >= a[i - 1] && (m - a[i] >= a[i - 1])) a[i] = min(a[i], m - a[i]);

        else if(a[i] >= a[i - 1]) a[i] = a[i];

        else if((m - a[i] >= a[i - 1])) a[i] = m - a[i];

        else {
            cout << "No" << '\n';
            return;
        }
    }

    cout << "Yes" << '\n';
    return;

}


int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        sol();
    }
    return 0;   
}

