#include <bits/stdc++.h>
using namespace std;

void sol() {
    int a[1001] = {0}, b[1001] = {0}, n, Max = 0;
        cin >> n;
        for(int i = 1; i < n + 1; i++) {
            int x;
            cin >> x;
            if(!b[x]) b[x]++;
            else a[x]++;
            Max = max(Max, x);
        }
        while(a[Max] > b[Max]) {
            a[Max]--;
            b[Max]++;
        }

        for(int i = Max; i > 0; i--) {
            
            while(a[i] > b[i]) {
                a[i]--;
                b[i]++;
            }
            for(int j = i; a[i] < b[i]; j--) {
                if(a[j - 1] > 0 ) {
                    a[j - 1]--;
                    if(!b[j]) {
                        b[j]++;
                        j++;
                    }
                    else {
                        a[j]++;
                        j += 2;
                    }
                    continue;
                }
                if(j == 1) {
                    cout << "No" << '\n';
                    return;
                }
            }
        }

        cout << "Yes" << '\n';
        return;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;

    while(t--) {
        sol();
    }
    return 0;
}