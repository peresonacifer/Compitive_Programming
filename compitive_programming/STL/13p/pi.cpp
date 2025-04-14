#include <bits/stdc++.h>
using namespace std;

void sol() {
    int n;
    cin >> n;
    char c;
    stack<char> stk;
    for(int i = 0; i < n; i++) {
        cin >> c;
        if(c == ')' && !stk.empty() && stk.top() == '(') stk.pop();
        if(c == '(') stk.push(c);
    }
    cout << stk.size() << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;

    cin >> t;
    while(t--) {
        sol();
    }
    return 0;
}
