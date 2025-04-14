#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    map<int, int> v;
    vector<string> dp(n + 1, "0");
    set<int> st;
    for(int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        st.insert(x);
    }
    string s = "2,5,5,4,5,6,3,7,6";
    for(int i = 1; i <= 9; i++) {
        if(st.find(i) == st.end()) continue;
        v[i] = s[(i - 1) * 2] - '0';
    }
    dp[0] = "";
    for(auto it = v.rbegin(); it != v.rend(); it++) {
        for(int j = it -> second; j <= n; j++) {

            string s = dp[j - (it -> second)]+ char(it -> first + '0');
            if(s[0] != '0' && (s.size() > dp[j].size() || (s.size() == dp[j].size() && s > dp[j]))) {
                dp[j]= s;
            }   
        }
    }
    cout << dp[n]<< '\n';

    return 0;
}