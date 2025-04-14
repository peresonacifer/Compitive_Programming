#include<bits/stdc++.h>
using namespace std;
int N = 1e6;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    pair<int, int> pr[N] = {{0, 0}};
    int x;
    int ans = N;
    for(int i = 0; i < n; i++) {
        cin >> x;
        if(pr[x].first > 0) {
            ans = min(ans, i - pr[x].second);
            pr[x].second = i;
        }
        else {
            pr[x].first++;
            pr[x].second = i;
        }    
    }

    cout << ((ans == N) ? -1 : ans + 1) << '\n';
    return 0;   
}

