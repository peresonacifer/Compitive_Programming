#include<bits/stdc++.h>
using namespace std;

void sol() {
    int n;
    cin >> n;
    if(n < 1000 || n > 9999) {
        cout << "Failure Input\n";
        return;
    }
    map<int, int> mp;
    for(int i = 0; i < 4; i++) {
        int x = n % 10;
        mp[x]++;
        n /= 10;
    }
    int cnt = 0;
    for(auto it : mp) {
        if(it.second > 2) {
            cout << "No\n";
            return;
        }
        else if(it.second == 2) {
            cnt++;
        }
    }

    if(cnt == 2) cout << "No\n";
    else cout << "Yes\n";
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
