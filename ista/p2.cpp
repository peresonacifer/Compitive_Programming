#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<pair<string, set<string>>> v(10);
bool ok[10];

void sol() {
    int n, m;
    cin >> n;
    cin.ignore();    
    string s;

    for(int i = 0; i < n; i++) {
        getline(cin,s);
        istringstream ss(s);
        ss >> v[i].first;
        string s2;
        while(ss >> s2) v[i].second.insert(s2);       
    }
    cin >> m;
    cin.ignore();
    for(int i = 0; i < m; i++) {
        getline(cin, s);
        vector<string> vs;
        string s2;
        fill(begin(ok), end(ok), false);
        for(int j = 0; j < s.size(); j++) {
            if(s[j] == ' ') continue;
            if(s[j] == '+') {
                for(int k = 0; k < n; k++) {
                    bool chk = true;
                    for(int q = 0; q < vs.size(); q++) {
                        if(v[k].second.find(vs[q]) == v[k].second.end()) {
                            chk = false;
                            break;
                        }
                    }
                    if(chk) ok[k] = true;
                }

                vs.clear();
                continue;
            }
            s2 += s[j];
            if(s2.size() == 2) {
                vs.push_back(s2); 
                s2 = "";
            }
            if(j == s.size() - 1) {
                for(int k = 0; k < n; k++) {
                    bool chk = true;
                    for(int q = 0; q < vs.size(); q++) {
                        if(v[k].second.find(vs[q]) == v[k].second.end()) {
                            chk = false;
                            break;
                        }
                    }
                    if(chk) ok[k] = true;
                }
            }
        }

        bool found = false;
        for(int h = 0; h < n; h++) {
            if(ok[h]) {
                cout << v[h].first << " ";
                found = true;
            }    
        } 
        if(!found) cout << "None";
        cout << '\n';
    }
    /*
5
Alps MT NP WD
Bali BE UR
Kyoto CU UR
Amazon WD NP LA
Tahoe LA MT
2
MT BE+NP LA
CU+MT WD
  
    */
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--) {
        sol();
    }
    return 0;
}
