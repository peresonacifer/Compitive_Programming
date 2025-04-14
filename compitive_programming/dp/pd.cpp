#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    if(s.size() % 2) {
        cout << "No" << '\n';
        return 0;
    }
    stack<char> stk;
    for(auto  i = 0; i < s.length(); i++) {
        if(s[i] == '[' || s[i] == '(' || s[i] == '<') stk.push(s[i]);
        else {
            if(stk.empty()) {
                cout << "No" << '\n';
                return 0;
            }
            if((stk.top() == '[' && s[i] == ']') || (stk.top() == '(' && s[i] == ')') || (stk.top() == '<' && s[i] == '>'))
                stk.pop();
            else {
                cout << "No" << '\n';
                return 0;
            }
        }
    }
    cout << "Yes" << '\n'; 
    return 0;
}