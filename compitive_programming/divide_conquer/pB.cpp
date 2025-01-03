#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll maxCrossingSum(vector<int>& arr, int left, int mid, int right) {
    ll leftsum = INT64_MIN, rightsum = INT64_MIN, sum = 0;

    for (int i = mid; i >= left; --i) {
        sum += arr[i];
        leftsum = max(leftsum, sum);
    }

    sum = 0;
    for (int i = mid + 1; i <= right; ++i) {
        sum += arr[i];
        rightsum = max(rightsum, sum);
    }

    return leftsum + rightsum;
}

ll maxSubArraySum(vector<int>& arr, int left, int right) {
    if (left == right) return arr[left];
    int mid = (right + left) / 2;

    ll leftmax = maxSubArraySum(arr, left, mid);
    ll rightmax = maxSubArraySum(arr, mid + 1, right);
    ll crossmax = maxCrossingSum(arr, left, mid, right);

    return max({leftmax, rightmax, crossmax});
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << maxSubArraySum(arr, 0, n - 1) << '\n';
    return 0;
}
