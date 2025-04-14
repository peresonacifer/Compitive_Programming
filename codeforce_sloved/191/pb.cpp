#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1e5
vector<int> seq;


void init() {
    for(int i  = M; i < 2 * M; i++) seq.push_back(i + 1);
    
    //for(int i = 0; i < M; i++) cout << seq[i] << " ";

}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    init();
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cout << seq[i] << " ";
    cout << '\n';
    return 0;
}
