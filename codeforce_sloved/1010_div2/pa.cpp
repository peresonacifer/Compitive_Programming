#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n, m;
        cin >> n >> m;
        char a[n][m]; 
        int r = 0, c = 0;

        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = 0; j < m; j++){
                cin >> a[i][j];
                if(a[i][j] == '1') cnt++;
            }
            if(cnt % 2) r++;
        }
        for(int j = 0; j < m; j++){
            int cnt = 0;
            for(int i = 0; i < n; i++){
                if(a[i][j] == '1') cnt++;
            }
            if(cnt % 2) c++;
        }
        cout << max(r, c) << '\n';
    }
    

    return 0;
}