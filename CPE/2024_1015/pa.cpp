#include<bits/stdc++.h>
using namespace std;

bool cmp(const pair<char,int>& a, const pair<char,int>& b) {
    if(a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}
int main() {
    int t;
    cin >> t;
    int cnt[26] = {0};
    cin.ignore();
    for(int i = 0; i < t; i++) {
        string s;
        getline(cin, s);
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '\n') break;
            if(s[i] >= 'A' && s[i] <= 'Z') cnt[s[i] - 'A']++;
            if(s[i] >= 'a' && s[i] <= 'z') {
                s[i] ^= 32;
                cnt[s[i] - 'A']++;
            }
        }
    }
    pair<char, int> pr[26];
    for(int i = 0; i < 26; i++) pr[i] = {i + 'A', cnt[i]};

    sort(pr, pr + 26, cmp);
    for(int i = 0; i < 26; i++) {
        if(pr[i].second < 1) break; 
        cout << pr[i].first << " " << pr[i].second << '\n';
    }

    return 0;
}
/*
3
This is a test.
Count me 1 2 3 4 5.
Wow!!!! Is this question easy?

*/