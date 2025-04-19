#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1)

int main() {
    long double a, b, x;
    cin >> a >> b >> x;
    long double theta;

    if(x < (a * a * b) / 2) theta = atan((long double)(a * b * b) / (2 * x)) * 180 / pi;
    else theta =  atan((long double)2 * ((a * a * b) - x) / (a * a * a)) * 180 / pi;
    
    cout << fixed << setprecision(10) << theta << '\n';
    return 0;
}
