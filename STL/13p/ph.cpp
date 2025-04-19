#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i]; 
    }

    sort(v.begin(), v.end(), [](const string& a, const string& b) {
        return a + b < b + a;
    });

    for (const string& s : v) {
        cout << s;
    }
    cout << "\n";

    return 0;
}
