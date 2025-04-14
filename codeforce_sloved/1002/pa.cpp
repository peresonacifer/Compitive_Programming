#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        set<int> a, b;
        for(int k = 0; k < 2; k++) {
            for(int i = 0; i < n; i++) {
                int x;
                cin >> x;
                if(!k) a.insert(x);
                else b.insert(x);
            }
        }

        if((a.size() <= 1 && b.size() <= 2 )|| (b.size() <= 1 && a.size() <= 2)) cout << "No" << '\n';
        else if(a == b && n <= 3) cout << "No" << '\n';
        else cout << "Yes" << '\n';
    }
    return 0;
}




