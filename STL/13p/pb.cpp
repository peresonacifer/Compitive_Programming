#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    pair<string, int> pr[n];
    for(int i = 0; i < n; i++) {
        cin >> pr[i].first >> pr[i].second;
    }

    sort(pr, pr + n, [](auto a, auto b) {
        return a.second > b.second;
    });

    cout << pr[1].first << '\n';
    return 0;
}