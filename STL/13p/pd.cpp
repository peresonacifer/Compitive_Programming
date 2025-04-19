#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    cin.ignore();
    string s;
    while(t--) {
        stack<char> stk;
        bool ok = true;
        getline(cin, s); //important!!!
        for(size_t i = 0; i < s.size(); i++) {
            if(s[i] == '(' || s[i] == '[') stk.push(s[i]);
            else {
                if(stk.empty()) {
                    ok = false;
                    break;
                }
                if((s[i] == ')' && stk.top() == '(') || (s[i] == ']' && stk.top() == '[')) stk.pop();
                else {
                    ok = false;
                    break;
                }
            }
        }
        cout << ((ok && stk.empty())? "Yes" : "No") << '\n';
    }
    return 0;
}