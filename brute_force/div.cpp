#include<bits/stdc++.h>
using namespace std;

void sol(int n) {
    int ar[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<pair<int, int>> ans;
    do {
        int a = 0, b = 0;

        for(int i = 0; i < 5; i++) {
            a += ar[i] * pow(10, i);  
        }

        for(int i = 5; i < 10; i++) {
            b += ar[i] * pow(10, i % 5);
        }
        // cout << "a: " << a << " b " << b << '\n';

        if(a < b) continue;
        
        if(b * n == a) {
            ans.push_back(make_pair(a, b));
        }   

    }while(next_permutation(ar, ar + 10));

    if(ans.empty()) {
        cout << "There are no solutions for " << n << ".\n\n";
    } else {
        for(const auto& [a, b] : ans) {
            cout << setw(5) << setfill('0') << a << " / "
                 << setw(5) << setfill('0') << b << " = " << n << '\n';
        }
    }

}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    while(1) {
        cin >> n;
        if(n == 0) break;
        else sol(n);
    }

    return 0;
}