#include <bits/stdc++.h>
using namespace std;
set<string> st;
void dfs (int cur, int ed, string str, string s){
    if(str.size() == 3) {
        st.insert(str);
        return;
    }
    string ss(str);
    for(int i = cur; i < ed; i++) {
        str += s[i];
        dfs(i + 1, ed, str, s);
        str = ss;
    }

}


int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n;
    cin >> n;
    cin.ignore();
    string s;
    getline(cin, s);
    dfs(0, n, "", s);
    cout << st.size();
    return 0;
}