#include <bits/stdc++.h>
using namespace std;

int main() {
    // 1️⃣ set（不重複，自動排序）
    set<int> s = {5, 2, 8, 5}; // 5 會被存一次
    cout << "Set elements: ";
    for (int x : s) cout << x << " ";  // 輸出：2 5 8
    cout << '\n';

    // 查找與刪除
    if (s.find(5) != s.end()) cout << "5 存在\n";
    s.erase(2);
    cout << "刪除 2 後: ";
    for (int x : s) cout << x << " ";  // 輸出：5 8
    cout << '\n';

    // 2️⃣ lower_bound / upper_bound
    set<int> s2 = {1, 3, 5, 7, 9};
    auto lb = s2.lower_bound(4);
    auto ub = s2.upper_bound(5);
    if (lb != s2.end()) cout << "lower_bound(4): " << *lb << '\n'; // 5
    if (ub != s2.end()) cout << "upper_bound(5): " << *ub << '\n'; // 7

    // 3️⃣ multiset（允許重複）
    multiset<int> ms = {1, 2, 2, 3, 3, 3};
    cout << "multiset 元素: ";
    for (int x : ms) cout << x << " ";  // 輸出：1 2 2 3 3 3
    cout << '\n';

    // 刪除所有 3
    ms.erase(3);
    cout << "刪除 3 後: ";
    for (int x : ms) cout << x << " ";  // 輸出：1 2 2
    cout << '\n';

    // 4️⃣ unordered_set（哈希表）
    unordered_set<int> us = {10, 20, 30, 20, 10};
    cout << "unordered_set: ";
    for (int x : us) cout << x << " ";  // 順序不固定
    cout << '\n';

    return 0;
}
