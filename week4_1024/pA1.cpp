#include <bits/stdc++.h>
using namespace std;

int F[200000];

void init(int N) {
    for(int i = 0; i < N; i++) {
        F[i] = i;
    }
}

int find(int x) {
    if (x == F[x]) return x;
    return find(F[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);

    if (x!=y) F[x] = y;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int N, Q;
    cin >> N >> Q;
    init(N);
    for (int i = 0; i < Q; i++) {
        int t, v, q;
        cin >> t >> v >> q;
        if (t) {
            if (find(v) == find(q)) {
                cout << 1 << '\n';
            }
            else cout << 0 << '\n';
        }
        else {
            merge(v, q);
        }
    }
    return 0;
}



