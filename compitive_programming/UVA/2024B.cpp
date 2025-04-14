#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    vector<int> vtr;
    int x;
    while(cin >> x) {
        if(x == 0) break;
        vtr.push_back(x);
    }
    cout << "PERFECTION OUTPUT" << '\n';
    for(size_t i = 0; i < vtr.size(); i++) {
        int sum = 1;
        int check;
        
        for(int j = 2; j * j <= vtr[i]; j++) {
            if(!(vtr[i] % j) )  sum += (vtr[i] / j + j);
            if(j * j == vtr[i]) sum -= j;
    
            if(sum > vtr[i]) {
                check = 1;
                break;
            }
            else if(sum == vtr[i]) check = 2;
            else check = 3;
        }
        if(check == 1) cout << setw(5) << vtr[i] << "  ABUNDANT" << '\n';
        else if(check == 2) cout << setw(5) << vtr[i] << "  PERFECT" << '\n';
        else cout << setw(5) << vtr[i] << "  DEFICIENT" << '\n';
    }   
    cout <<"END OF OUTPUT" << '\n';
    return 0;
}
