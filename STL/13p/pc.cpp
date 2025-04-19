#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, x ;
    cin >> n >> x;
    int ar[n];
    set<int> st;
    for(int i = 0; i < n; i++) {
        cin >> ar[i];
        st.insert(ar[i]);
    }
    for(int i = 0; i < n; i++) {
        if(st.find(ar[i] + x) != st.end() || st.find(ar[i] + x) != st.end()) {
            cout << "Yes" << '\n';
            return 0;
        }
    }
    cout << "No" << '\n';
    return 0;
}