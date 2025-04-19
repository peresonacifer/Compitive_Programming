#include<bits/stdc++.h>
using namespace std;

static int times = 0; 
void Merge(vector<int> &vtr, int left, int mid, int right) {
    int n1 = mid - left, n2 = right - mid;
    vector<int> vtr1(n1 + 1), vtr2(n2 + 1);
    for(int i = 0; i < n1; i++) vtr1[i] = vtr[left + i];
    for(int j = 0; j < n2; j++) vtr2[j] = vtr[mid + j];
    
    vtr1[n1] = INT_MAX; vtr2[n2] = INT_MAX;
    int i = 0, j = 0;

    for(int k = left; k < right; k++) {
        times++;
        if(vtr1[i] <= vtr2[j]) {
            vtr[k] = vtr1[i++];
        }
        else {
            vtr[k] = vtr2[j++];
        }
    }
}

void Merge_sort(vector<int> &vtr, int left, int right) {
    if(left + 1 < right) {
        int mid = (right + left) / 2;
        Merge_sort(vtr, left, mid);
        Merge_sort(vtr, mid, right);
        Merge(vtr, left, mid, right);
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector<int> vtr(n); 
    for(int &i : vtr) {
        cin >> i;
    }
    Merge_sort(vtr, 0, n);
    for(int p : vtr) {
        cout << p << " ";
    }
    cout << '\n' << times;

    return 0;
}