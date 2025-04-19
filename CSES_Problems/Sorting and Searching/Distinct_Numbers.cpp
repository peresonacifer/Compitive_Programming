#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    set<int> st;
    int ans = 0;
    for(int i = 0; i < n ; i++) {
        int x;
        cin >> x;
        if(st.find(x) == st.end()) {
            st.insert(x);
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}