#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    map<string, string> mp = {{"HELLO", "ENGLISH"}, {"HOLA", "SPANISH"}, {"HALLO", "GERMAN"}, {"BONJOUR", "FRENCH"}, {"CIAO", "ITALIAN"}, {"ZDRAVSTVUJTE", "RUSSIAN"}};

    string s;
    int i = 1;
    while(cin >> s) {
        if(s == "#") break;
        if(mp.find(s) == mp.end()) cout << "Case " << i << ": " << "UNKNOWN" << '\n';
        else cout << "Case " << i << ": " << mp[s] << '\n';
        i++;
    }

    return 0;
}
