//(???)? ()(()) ((()))
//() ((

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
ll ans = 0;

void sol() {
    string str;
    stack<char> stk;
    getline(cin, str);
    int num_qm = 0, num_lb = 0, num_rb = 0;
    for(int i = 0; i < str.size(); i++) {
        if(str[0] == ')' || str[str.size() - 1] == '(') {
            ans = -1;
        }
        else{
            if(str[i] == '(') {
                num_lb++;
                if()
            }
            else if(str[i] == ')') num_rb++;
            else num_qm++;
        }
    }
    if(abs(num_lb - num_rb) != num_qm && num_lb != num_rb) {
        ans = -1;
    }
    




    return;
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    sol();
    return 0;
}