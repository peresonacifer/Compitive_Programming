#include <bits/stdc++.h>
using namespace std;
#define ll long long;
#define pii pair<int, int>
set<long long> st;

bool cmp(int a, int b) {
    return a > b;
}

void sol() {
    int n;
    cin >> n;    
    long long num = 0;
    vector<long long> v(2 * n);
    for(int i = 0 ; i < 2 * n; i++) {
        cin >> v[i];
        st.insert(v[i]);
    }
    sort(v.begin(), v.end(), cmp);
    for(int i = 0; i < 2 * n; i += 2) {
        num += (v[i] - v[i + 1]);
    }
    int j = 1;
    while(st.find(num) != st.end()) {
        num  = num + (-2) * (v[j] - v[j + 1]);
        swap(v[j], v[j+1]);
        j += 2;
        if(j >= 2 * n - 1) j = 1;
    }
    cout << num << " ";
    for(int i = 0; i < 2 * n; i++) cout << v[i] << " ";
    cout << '\n';
    st.clear();
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--) {
        sol();
    }

    return 0;
}