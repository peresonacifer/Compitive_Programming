#include<bits/stdc++.h>
using namespace std;

int main() {
    int a = 0, b = 5;
    while(a < b) {
        if(a % 2 == 0) {
            b--;
            continue;
        }
        cout << a << " ";
        a++;
    }
    cout << '\n';
    
    cout << "WTH";
    return 0;
}