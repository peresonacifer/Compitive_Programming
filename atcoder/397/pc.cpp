#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, x, id = -1;
    cin >> n;
    map<int, pair<int, int>> mp;
    
    for(int i = 1; i <= n; i++) {
        //int x;
        cin >> x;
        if(mp.find(x) == mp.end()) mp[x] = {1, i};
        else mp[x] = {2 , i};
    }
    int cur = 0;
    for(auto x: mp) {
        if(x.second.first == 1) {
            if(x.first > cur) {
                cur = x.first;
                id = x.second.second;
            }
        }
    }
    cout << id << '\n';
    return 0;
}