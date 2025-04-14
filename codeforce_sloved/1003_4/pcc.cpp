#include<bits/stdc++.h>
using namespace std;
void sol() {
    int n, m;
    cin >> n >> m;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(m);
    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(b.begin(), b.end());

    a[0] = min(a[0], b[0] - a[0]);

    for(int i = 1; i < n; i++) {
        int x = (lower_bound(b.begin(), b.end(), a[i - 1] + a[i]) - b.begin());
        if(x == m) {
            if(a[i] < a[i - 1]) {
                cout << "No" << '\n';
                return;
            }
            else continue;
        }
 
        if(a[i] >= a[i - 1] && (b[x] - a[i] >= a[i - 1])) a[i] = min(a[i], b[x] - a[i]);

        else if(a[i] >= a[i - 1]) a[i] = a[i];

        else if((b[x] - a[i] >= a[i - 1])) a[i] = b[x] - a[i];

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

