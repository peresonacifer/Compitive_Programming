# include <iostream>
using namespace std;

const int MOD = 1000000007;

long long fast_pow(long long base, long long exp, long long mod)
{
    long long result = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
        // cout << "exp: " << exp << endl;
    }    
    return result;
}






int main()   
{
    long long n;
    cin >> n;
    cout << fast_pow(2, n, MOD) << endl;
    return 0;
}