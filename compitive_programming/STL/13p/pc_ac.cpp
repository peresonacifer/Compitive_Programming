#include<bits/stdc++.h>
using namespace std;
int ar[200000];


int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, x ;
    cin >> n >> x;
    for(int i = 0; i < n; i++) cin >> ar[i];
    sort(ar, ar + n);
    for(int i = 0, j = 0; i < n; i++) {
        while (ar[j] - ar[i] < x && j < n) j++;
        if(ar[j] - ar[i] == x) {
            cout << "Yes" << '\n';
            return 0;
        }
    }
    cout << "No" << '\n';
    return 0;
}