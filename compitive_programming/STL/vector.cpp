#include <iostream>
#include <vector>
#include <algorithm>  // sort, reverse, binary_search, lower_bound, upper_bound
#include <tuple>      // tuple, make_tuple, get

using namespace std;

int main() {
    // ===== 1. 創建與初始化 vector =====
    vector<int> v1 = {5, 3, 9, 1, 7};
    vector<int> v2(5, 100); // 初始化 5 個元素，每個值為 100

    cout << "v1 初始值: ";
    for (int x : v1) cout << x << " ";
    cout << "\n";

    // ===== 2. 存取元素 =====
    cout << "v1[2] = " << v1[2] << "\n";
    cout << "v1.at(2) = " << v1.at(2) << "\n";
    cout << "v1.front() = " << v1.front() << "\n";
    cout << "v1.back() = " << v1.back() << "\n";

    // ===== 3. 修改 vector =====
    v1.push_back(8);  // 新增元素
    v1.pop_back();     // 刪除最後一個元素
    v1.insert(v1.begin() + 2, 99);  // 在索引 2 插入 99
    v1.erase(v1.begin());           // 刪除第一個元素

    cout << "v1 修改後: ";
    for (int x : v1) cout << x << " ";
    cout << "\n";

    // ===== 4. 排序與搜尋 =====
    sort(v1.begin(), v1.end());  // 升序排序
    cout << "排序後: ";
    for (int x : v1) cout << x << " ";
    cout << "\n";

    reverse(v1.begin(), v1.end()); // 反轉排序
    cout << "反轉排序: ";
    for (int x : v1) cout << x << " ";
    cout << "\n";

    // 二分搜尋（binary_search 需要排序後使用）
    sort(v1.begin(), v1.end());
    cout << "是否存在 7? " << (binary_search(v1.begin(), v1.end(), 7) ? "是" : "否") << "\n";

    // lower_bound & upper_bound
    auto lb = lower_bound(v1.begin(), v1.end(), 5); // 第一個 >= 5 的元素
    auto ub = upper_bound(v1.begin(), v1.end(), 5); // 第一個 > 5 的元素
    cout << "lower_bound(5): " << (lb != v1.end() ? to_string(*lb) : "不存在") << "\n";
    cout << "upper_bound(5): " << (ub != v1.end() ? to_string(*ub) : "不存在") << "\n";

    // ===== 5. 迭代器遍歷 =====
    cout << "使用迭代器遍歷: ";
    for (auto it = v1.begin(); it != v1.end(); ++it)
        cout << *it << " ";
    cout << "\n";

    // ===== 6. 進階功能 =====
    vector<int> v3 = {10, 20, 30};
    v1.swap(v3); // 交換 v1 和 v3
    cout << "交換後 v1: ";
    for (int x : v1) cout << x << " ";
    cout << "\n";

    v1.shrink_to_fit(); // 釋放多餘記憶體

    // ===== 7. tuple 與 vector 搭配使用 =====
    tuple<string, int, double> t1 = make_tuple("Apple", 10, 5.5);
    vector<tuple<string, int, double>> items;
    items.push_back(make_tuple("Banana", 3, 2.5));
    items.push_back(make_tuple("Orange", 5, 3.5));

    // 取得 tuple 內的值
    string name;
    int quantity;
    double price;
    tie(name, quantity, price) = items[0];

    cout << "Tuple 第一個元素: " << name << " " << quantity << " " << price << "\n";

    // tuple 排序 (依據數量升序)
    sort(items.begin(), items.end(), [](auto& a, auto& b) {
        return get<1>(a) < get<1>(b);
    });

    cout << "排序後的 Tuple 第一個: " << get<0>(items[0]) << "\n";

    return 0;
}
