#include <bits/stdc++.h>
using namespace std;

int main() {
    // 定義 bitset，大小為 8 位元
    bitset<8> b1("11010101");

    cout << "b1: " << b1 << endl;  // 輸出：11010101

    // 設置和重置位元
    b1.set(3);  // 設置第 3 位為 1
    b1.reset(0);  // 設置第 0 位為 0
    cout << "b1 設置第 3 位並重置第 0 位後: " << b1 << endl;

    // 切換位元
    b1.flip(2);  // 切換第 2 位
    cout << "b1 切換第 2 位後: " << b1 << endl;

    // 檢查某一位是否為 1
    if (b1.test(3)) {
        cout << "第 3 位為 1" << endl;
    } else {
        cout << "第 3 位為 0" << endl;
    }

    // 輸出 bitset 的大小
    cout << "bitset 的大小: " << b1.size() << endl;

    return 0;
}
