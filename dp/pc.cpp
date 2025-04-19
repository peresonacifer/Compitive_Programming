#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    for(int i = s.size() - 1; i > 0 ; i--) {
        if(s[i] == 'A'&& s[i - 1] == 'W') s.replace(i - 1, 2 , "AC");
    }
    cout << s << '\n';
    return 0;
}