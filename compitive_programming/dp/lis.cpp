#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> lis;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(lis.size() == 0 || x > lis.back()) lis.push_back(x);
        else {
            auto it = lower_bound(lis.begin(), lis.end(), x);
            *it = x;
        }
    }
    cout << lis.size() << '\n';
    return 0;
}