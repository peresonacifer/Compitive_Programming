#include <bits/stdc++.h>
using namespace std;

void sol() {
    int n, x;
    cin >> n >> x;

    set<int> myset;
    for (int i = 0; i < n; i++) {
        int j;
        cin >> j;
        myset.insert(j);
    }

    for (set<int>::iterator it = myset.begin(); it != myset.end(); ++it) {
        int Aj1 = *it + x, Aj2 = *it - x;
        if(myset.find(Aj1) != myset.end() || myset.find(Aj2) != myset.end()) {
            cout << "Yes";
            return;
        }
    }
    cout << "No";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    sol();
    return 0;
}
