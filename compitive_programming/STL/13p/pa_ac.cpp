#include <bits/stdc++.h>
//#define int long long
#define f first
#define s second
#define pb push_back
 
using namespace std;
using li = long long;
using ld = long double;
 
 
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    string s;
    cin >> s;
 
    bool F = 1;
 
    for(int i = 1; i < s.size(); i++)
        if(s[i] >= 'a' && s[i] <= 'z')
            F = 0;
 
    for(int i = 0; i < s.size(); i++)
        if(F)
            s[i] ^= 32;
 
    cout << s;
}