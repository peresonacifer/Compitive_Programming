#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int x, cnt[14], ch1 = 0, ch2 = 0;
    memset(cnt, 0, sizeof(cnt));
    
    for(int i = 0; i < 7; i++) {
        cin >> x;
        cnt[x]++;
    }
    for(int i = 1; i <= 13; i++) {
        if(cnt[i] > 1) {
            if(cnt[i] > 2 && !ch2) ch2 = 1;
            else ch1 = 1;
        } 
    }
    if(ch2 && ch1) cout << "Yes";
    else cout << "No";
    cout << '\n';
    return 0;
}
