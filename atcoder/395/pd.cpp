#include<bits/stdc++.h>
using namespace std;
int N = 1e6;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, q;
    cin >> n >> q;
    int ty, a, b;
    int A[n + 1], B[n + 1], C[n + 1];
    for(int i = 1; i <= n; i++) {
        A[i] = i;
        B[i] = i;
        C[i] = i;
    }
    for(int i = 0; i < q; i++) {
        cin >> ty;
        if(ty == 1) {
            cin >> a >> b;
            A[a] = C[b]; 
        }
        else if(ty == 2) {
            cin >> a >> b;
            swap(C[a], C[b]);
            swap(B[C[a]],B[C[b]]);
        }
        else {
            cin >> a;
            cout << B[A[a]] << '\n';
        }
    }
    return 0;   
}

