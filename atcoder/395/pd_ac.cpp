#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000000;
const int INF = 100000000;
int main(){
  int N, Q;
  cin >> N >> Q;
  vector<int> A(N), B(N), C(N);
  for (int i = 0; i < N; i++){
    A[i] = i;
    B[i] = i;
    C[i] = i;
  }
  for (int i = 0; i < Q; i++){
    int t;
    cin >> t;
    if (t == 1){
      int a, b;
      cin >> a >> b;
      a--;
      b--;
      A[a] = C[b];
    }
    if (t == 2){
      int a, b;
      cin >> a >> b;
      a--;
      b--;
      swap(C[a], C[b]);
      swap(B[C[a]], B[C[b]]);
    }
    if (t == 3){
      int a;
      cin >> a;
      a--;
      cout << B[A[a]] + 1 << endl;
    }
  }
}