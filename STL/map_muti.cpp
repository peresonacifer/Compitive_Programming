#include <bits/stdc++.h>
using namespace std;

int main() {
    map<string, int> m;

    // 插入元素
    m["apple"] = 3;
    m["banana"] = 2;
    m["cherry"] = 5;

    // 遍歷輸出
    cout << "Map 元素：" << endl;
    for (const auto& pair : m) {
        cout << pair.first << ": " << pair.second << endl;
    }

    // 查找元素
    if (m.find("banana") != m.end()) {
        cout << "找到 banana, 值為：" << m["banana"] << endl;
    } else {
        cout << "banana 不存在" << endl;
    }

    // 刪除元素
    m.erase("apple");
    cout << "刪除 apple 後：" << endl;
    for (const auto& pair : m) {
        cout << pair.first << ": " << pair.second << endl;
    }
    
    
    multimap<string, int> mm;

    // 插入元素
    mm.insert({"apple", 3});
    mm.insert({"banana", 2});
    mm.insert({"cherry", 5});
    mm.insert({"banana", 6});  // 重複 key

    // 遍歷輸出
    cout << "Multimap 元素：" << endl;
    for (const auto& pair : mm) {
        cout << pair.first << ": " << pair.second << endl;
    }

    // 查找元素
    auto range = mm.equal_range("banana");
    cout << "所有 banana 的值：" << endl;
    for (auto it = range.first; it != range.second; ++it) {
        cout << it->second << " ";
    }
    cout << endl;

    // 刪除元素
    mm.erase("apple");
    cout << "刪除 apple 後：" << endl;
    for (const auto& pair : mm) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}
