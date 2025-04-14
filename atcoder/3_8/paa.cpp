#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    stack<int> stk;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    long long ans = 0;

    for(int i = 0; i < n; i++) {
        if(max(v[i] + v[i + 1] , 0) == 0) i++;
        ans += v[i];
    }
    return 0;
}