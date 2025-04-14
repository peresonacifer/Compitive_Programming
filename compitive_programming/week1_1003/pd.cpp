#include<bits/stdc++.h>
using namespace std;

void sol() {
    int k, n;
    cin >> k >> n;

    int s = k - n; 
    cout << '\\';
    for(int i = n; i > 0; i--) {
        cout << 'Y';
        if(i > 1) {
            int itv = s / (i - 1);
            for(int j = 0; j < itv; j++) {
                cout << '_';
            }
            s -= itv;
        }
    }
    cout << '/';
    return;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    sol();
    return 0; 
}