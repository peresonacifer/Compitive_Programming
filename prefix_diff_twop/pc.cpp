#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    long long t, n, x, sum, cnt;
    cin >> t;
    while(t--) {
        map<int, int> mp;
        cin >> n;
        sum = cnt = 0;
        string s;
        cin >> s; 
        for(int i = 0; i < n; i++) {
            sum += s[i] - '0';
            if(sum == i + 1) cnt++;
            if(mp.find(sum - i) != mp.end()) cnt += mp[sum - i];
            mp[sum - i]++;
        }
        cout << cnt << '\n';
    }
    
    return 0;
}