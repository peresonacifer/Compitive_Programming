#include <bits/stdc++.h>
using namespace std;

void sol() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    for(int i = 0; i < s1.size(); i++) {
        if(s1[i] != ' ' && (s1[i] < 'A' || s1[i] > 'Z') && (s1[i] < 'a' || s1[i] > 'z')) s1[i] = ' ';
    }
    for(int i = 0; i < s2.size(); i++) {
        if(s2[i] != ' ' && (s2[i] < 'A' || s2[i] > 'Z') && (s2[i] < 'a' || s2[i] > 'z')) s2[i] = ' ';
    }
    stringstream ss1(s1), ss2(s2);
    vector<string> ans;
    for(int i = 1; ss1 >> s1 && ss2 >> s2; i++) {
        if(s1 == s2) {
            i--;
            continue;
        }
        else {
            if(i % 2) ans.push_back(s1);
            else ans.push_back(s2);
        }
    }
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << (i == ans.size() - 1 ? "\n" : " ");
    }

}
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    string s;
    getline(cin, s);
    while(t--) {
        sol();
    }
    return 0;
}
/*
2 
That treasure was in City. 
That power is at Chiayi. 
You have go too Chiayi, now.
He need went to Taipei, now. 
*/