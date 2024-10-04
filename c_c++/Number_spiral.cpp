#include <iostream>
#include <vector>
using namespace std;

long long number_spiral(long long y, long long x) {
    if (y >= x) {
        if (y % 2 == 1) {
            return y * y - 2 * (y - 1) + x - 1;  // 行數奇數，從下往上
        } else {
            return y * y - x + 1;  // 行數偶數，從上往下
        }
    } else {
        if (x % 2 == 1) {
            return x * x - y + 1;  // 列數奇數，從左往右
        } else {
            return x * x - 2 * (x - 1) + y - 1;  // 列數偶數，從右往左
        }
    }
}

int main() {
    int t;
    cin >> t;  // 讀取測試次數
    vector<long long> results;  // 用於儲存結果
    results.reserve(t);  // 預留空間避免多次分配

    for (int i = 0; i < t; ++i) {
        long long y, x;
        cin >> y >> x;  // 讀取 y 和 x
        results.push_back(number_spiral(y, x));  // 計算結果並存儲
    }

    // 輸出結果
    for (const auto& result : results) {
        cout << result << endl;
    }

    return 0;
}
