//1033C Permutation Game
#include<bits/stdc++.h>
using namespace std;
bool w[10005];
int idx[10005], a[10005];

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        idx[a[i]] = i;
    }
    memset(w, false, sizeof(w));
    for(int ai = n - 1; ai >= 1; ai--) {
        for(int j = idx[ai]%ai; j <= n; j += ai) {
            if(j == 0 || j == idx[ai]) continue;
            if(a[j] > ai && !w[j]) w[idx[ai]] = true;
        }
    }

    for(int i = 1; i <= n; i++) {
        if(w[i]) cout << 'A';
        else cout << 'B';
    }
    cout << '\n';
    return 0;
}