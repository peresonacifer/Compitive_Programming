#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int ar[n];
    for(int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    // nth_element(ar, ar + k, ar + n);
    nth_element(ar, ar + k - 1, ar + n, greater<int>());
    cout << ar[k - 1] << '\n'; 
    // for(int i = 0; i < n; i++) {
    //     cout << ar[i] << " ";
    // }
    //  0  1   2  3  4  5
    //100 20  40 20 50 50 
//-->  50 50 100 40 20 20

// if a > b:
// ar[k - 1] < [ar[0], ar[k - 1])
// ar[k - 1] > (ar[k - 1], ar[n])
   return 0;
}
