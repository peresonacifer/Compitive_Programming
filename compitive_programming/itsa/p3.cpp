#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    char c;
    int n;
    string s;
    cin >> c >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //getline(cin, s);
    getline(cin, s);
    for(int i = 0; i < s.size(); i++) {
        int x;
        if(s[i] == ' ') x = 26;
        else if(s[i] >= 'A' && s[i] <= 'Z')  x = s[i] - 'A';
        else { 
            cout << s[i];
            continue;
        }
        x = (c == '+' ? x + n : x - n);
        if(x < 0) x += 27;
        x %= 27;
        if(x == 26) cout << ' ';
        else cout << char(x + 'A');
    }
    cout << '\n';
    
    return 0;
}