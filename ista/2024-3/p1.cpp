#include<bits/stdc++.h>
using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    
    return a.first < b.first; 
}

int main() {
    int n;
    cin >> n;
    pair<int, int> pr[n];
    for(int i = 0; i < n; i++) cin >> pr[i].first >> pr[i].second;

    sort(pr, pr + n, cmp);
    int t = n, m = 0, cur;
    while(t) {
        cur = 1;
        for(int i = 0; i < n; i++) {
            if(pr[i].first == 0) continue;
            if(pr[i].first >= cur) {
                pr[i].first = 0;
                cur = pr[i].second;
                t--;    
            }
        }
        m++;
    }
    cout << m << '\n';
    return 0;
}