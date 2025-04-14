#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll calc(vector<int>& v, int x){
    if(v.size() == 1) return 0;
    ll sum = 0, mt = 1;
    for(int i = v.size() - 2 ; i >= 0; i--) {
        sum += v[i] * mt * (v.size() - 1 - i);
        mt *= x;
    }

    return sum;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int x;
    while (cin >> x) {
        cin.ignore();
        vector<int> vtr;

        string line;
        getline(cin, line);
        stringstream ss(line);
        int co;
        while(ss >> co) vtr.push_back(co);
        cout << calc(vtr, x) << '\n';
    }

    return 0;
}

