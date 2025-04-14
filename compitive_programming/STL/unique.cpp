#include<iostream>
#include<algorithm>
using namespace std;

int n = 10;
int arr[10] = {4, 2, 1, 1, 1, 5, 2, 2, 4, 4};
 
int main(){
    sort(arr, arr+n);
    int k = unique(arr, arr+n) - arr;
    cout << k << endl;
    for(int i = 0; i < k; i++)    cout << arr[i] << " \n"[i+1==k];
    return 0;
}
