#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, r, c;
    cin >> n >> r >> c;
    string s;
    cin >> s;
    set<pair<int, int>> st;
    st.insert({0, 0});
    int x = 0, y = 0;
    for(int i = 0; i < n; i++) {
        switch(s[i]) {  
            case 'N': x--; break;
            case 'S': x++; break;
            case 'W': y--; break;
            case 'E': y++; break;
        }
        st.insert({x, y});
        cout << (st.find({x - r, y - c}) != st.end());
    }
    cout << '\n';
    return 0;
}