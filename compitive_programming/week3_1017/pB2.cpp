// 埃氏篩 --> Sieve of Eratosthenes and 線性篩
# include <bits/stdc++.h>
using namespace std;

void sol() {
    // int n = 10000;
    int n;
    cin >> n;
    
    // vector<int> isprime; //別用memset指派，用assign、fill、resize
    vector<int> isprime(n, 1);
    // isprime.resize(n + 1, 1);

    // n太大出不來(1000000多):
    // bool isprime[n + 1];
    // fill(isprime, isprime + n + 1, 1); 

    // memset(isprime, 1, sizeof(isprime)); //適合用於普通的 C 標準陣列（如 int arr[100]）
    // isprime[0] = isprime[1] = 0;

    vector<int> prime; 
    //線性篩:
    for(int i = 2; i <= n; i++){
        if(isprime[i]) prime.push_back(i);
        for(int j = 0; i * prime[j] <= n; j++){
            isprime[i * prime[j]] = 0;
            if(i % prime[j] == 0) break;
        }
    }


    // // n太大出不來 (埃氏篩) 45000多
    // for (int i = 2; i <= n; i++) {
    //     if(isprime[i]) {  
    //         prime.push_back(i);
    //         for (int j = i; j * i <= n; j++) {
    //             isprime[i * j] = 0;
    //         }
    //     }
    // }

    for (int i = 0; i < prime.size(); i += 100) cout << prime[i] << '\n';

}

int main() {
    sol();
    return 0;
} 