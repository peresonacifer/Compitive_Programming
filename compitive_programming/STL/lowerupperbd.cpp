#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    vector<int> arr = {9, 7, 5, 5, 3, 1}; // 降序排列
    int value = 5;

    // 使用自訂比較函式（降序排列）
    auto cmp = [](int a, int b) { return a > b; };

    auto lower = lower_bound(arr.begin(), arr.end(), value, cmp); //第一個不大於5的 : 5 
    // 找到第一個 "大於 5" 的元素
    // sort(arr.begin(), arr.end());
    // auto upper = upper_bound(arr.begin(), arr.end(), value);
    auto upper = upper_bound(arr.begin(), arr.end(), value, cmp); //第一個小於5的 : 3

    //
    if (lower != arr.end())
        cout << "lower_bound 指向: " << *lower << endl;
    else
        cout << "lower_bound 找不到符合條件的元素" << endl;

    if (upper != arr.end())
        cout << "upper_bound 指向: " << *upper << endl;
    else
        cout << "upper_bound 找不到符合條件的元素" << endl;

    return 0;
}
