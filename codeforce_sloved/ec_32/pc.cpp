#include<bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    string s;
    cin >> s;
    vector<int> ar[26];
    for(int i = 0; i < s.size(); i++) {
        ar[s[i] - 'a'].push_back(i);
        //cout << ar[i][0];
    }
    
    int d = s.size() / 2 + 1;
    //cout << 1;
    for(int i = 0; i < 26; i++) {
        //cout << 1;
        if(ar[i].size() == 0) continue;
        int D = 0;
        for(int j = 0; j < ar[i].size() - 1; j++) { 
            D = max(D, ar[i][j + 1] - ar[i][j]);
        }
        D = max(ar[i][0] - 0 + 1,  D);
        int x = s.size() - 1 - ar[i][ar[i].size() - 1] + 1;
        D = max(x, D);
        d = min(d , D);
    }
    cout << d << '\n';
    return 0;   
}

