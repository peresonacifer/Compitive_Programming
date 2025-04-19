#include<bits/stdc++.h>
using namespace std;

void sol() {
    set<int> st, ans;
    int n;
    cin >> n;
    vector<int> vtr(n);
    
    for(auto &c : vtr) {
        cin >> c;
    }
    
    for(int i = 0; i < n; i++) {
        if(vtr[i] != vtr[(i + 1) % n]) {
            if(st.find(vtr[i]) == st.end()) st.insert(vtr[i]);
            else ans.insert(vtr[i]);
        }
    }    
    if(!ans.empty()) {
        cout << "No" << '\n';
        for(auto p : ans) cout << p << ' ';
        cout << '\n';
    }
    else cout << "Yes" << '\n';

    return;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    sol();

    return 0;
}