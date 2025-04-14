#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> lis, idx(n);
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(lis.size() == 0 || x > lis.back()) {
            lis.push_back(x);
            idx[i] = lis.size();
        }
        else {
            auto pos = lower_bound(lis.begin(), lis.end(), x) - lis.begin();
            lis[pos] = x;
            idx[i] = pos + 1;
        }
    }
    int st = lis.size();
    vector<int> ans(st);
    for(int i = n - 1; i >= 0; i--) {
        if(idx[i] == st) {
            ans[--st] = i;
        }     
    }
    cout << ans.size() << '\n';
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << (i != ans.size() - 1 ? ' ' : '\n');
    }
    return 0;
}