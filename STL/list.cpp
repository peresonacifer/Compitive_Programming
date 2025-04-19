#include <bits/stdc++.h>
using namespace std;

int main() {
    // 建立一個空的 list
    list<int> lst;

    // 插入元素
    lst.push_back(5);    // 在尾端插入
    lst.push_front(2);   // 在前端插入
    lst.push_back(8);    // 在尾端插入

    // 輸出所有元素
    cout << "list 元素: ";
    for (int x : lst) cout << x << " ";  // 輸出：2 5 8
    cout << '\n';

    // 刪除元素
    lst.pop_back();  // 刪除尾端元素
    lst.pop_front(); // 刪除前端元素

    // 輸出刪除後的 list
    cout << "刪除元素後: ";
    for (int x : lst) cout << x << " ";  // 輸出：5
    cout << '\n';

    // 查找元素
    auto it = find(lst.begin(), lst.end(), 5);
    if (it != lst.end()) cout << "5 存在於 list 中\n";
    else cout << "5 不存在於 list 中\n";

    list<int> lst1 = {4, 1, 3, 5};
    list<int> lst2 = {9, 8, 7, 6};

    // 排序 list
    lst1.sort();
    lst2.sort();

    cout << "排序後 lst1: ";
    for (int x : lst1) cout << x << " ";  // 輸出：1 3 4 5
    cout << '\n';

    cout << "排序後 lst2: ";
    for (int x : lst2) cout << x << " ";  // 輸出：6 7 8 9
    cout << '\n';

    // 合併 lst1 和 lst2
    lst1.merge(lst2);

    cout << "合併後 lst1: ";
    for (int x : lst1) cout << x << " ";  // 輸出：1 3 4 5 6 7 8 9
    cout << '\n';

    // 刪除所有值為 3 的元素
    lst1.remove(3);

    cout << "刪除 3 後 lst1: ";
    for (int x : lst1) cout << x << " ";  // 輸出：1 4 5 6 7 8 9
    cout << '\n';

    return 0;

    return 0;
}
