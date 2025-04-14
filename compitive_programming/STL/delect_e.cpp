#include <bits/stdc++.h>
using namespace std;

int main() {
    list<int> data;
    int n, m;
    cin >> n >> m;
    unordered_multimap<int, list<int>::iterator> mp;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        data.push_back(x);
        mp.insert({x, prev(data.end())});
    }

    for (int i = 0; i < m; i++) {
        int y;
        cin >> y;
        auto range = mp.equal_range(y);
        vector<list<int>::iterator> to_erase;

        // 收集需要刪除的迭代器
        for (auto it = range.first; it != range.second; it++) {
            to_erase.push_back(it->second);
        }

        // 刪除元素及其左右相鄰元素
        for (auto it : to_erase) {
            // 確保迭代器未被刪除
            if (it == data.end()) continue;

            // 刪除左邊的元素
            if (it != data.begin()) {
                auto left_it = prev(it);
                // 從 mp 中刪除左邊的元素
                auto left_range = mp.equal_range(*left_it);
                for (auto mp_it = left_range.first; mp_it != left_range.second; mp_it++) {
                    if (mp_it->second == left_it) {
                        mp.erase(mp_it);
                        break;
                    }
                }
                data.erase(left_it);
            }

            // 刪除右邊的元素
            if (next(it) != data.end()) {
                auto right_it = next(it);
                // 從 mp 中刪除右邊的元素
                auto right_range = mp.equal_range(*right_it);
                for (auto mp_it = right_range.first; mp_it != right_range.second; mp_it++) {
                    if (mp_it->second == right_it) {
                        mp.erase(mp_it);
                        break;
                    }
                }
                data.erase(right_it);
            }

            // 刪除當前元素
            data.erase(it);
        }

        // 從 mp 中刪除所有等於 y 的元素
        mp.erase(y);
    }

    // 輸出剩餘的元素
    for (auto ele : data) {
        cout << ele << " ";
    }

    return 0;
}