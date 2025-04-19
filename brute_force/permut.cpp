// #include<bits/stdc++.h>
// using namespace std;

// vector<vector<int>> vtr;

// void permutation(vector<int> &elm, vector<int> v) {
//     if(elm.size() == 1) {
//         v.push_back(elm[0]);
//         vtr.push_back(v);
//         return;
//     }

//     for(int i = 0; i < elm.size(); i++) {
//         vector<int> v1(v);
//         v1.push_back(elm[i]);
//         vector<int> elm2(elm);
//         for(int j = i; j < elm2.size() - 1; j++) {
//             swap(elm2[j], elm2[j + 1]);
//         }
//         elm2.pop_back();
//         permutation(elm2, v1);
//     }
// }

// int main() {
//     vector<int> element = {1, 2, 3, 4}, v;
//     permutation(element, v);
//     for(int i = 0; i < vtr.size(); i++) {
//         for(int j = 0; j < vtr[i].size(); j++) {
//             cout << vtr[i][j] << ' ';
//         }
//         cout << '\n';
//     }

//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> vtr;

void permutation(vector<int> &elm, int start, vector<int> &current) {
    if (start == elm.size()) {
        vtr.push_back(current);
        return;
    }

    for (int i = start; i < elm.size(); i++) {
        swap(elm[start], elm[i]); // 選擇當前位置的元素
        current.push_back(elm[start]); // 加入結果
        permutation(elm, start + 1, current); // 遞迴處理下一層
        current.pop_back(); // 回溯
        swap(elm[start], elm[i]); // 恢復原始狀態
    }
}

int main() {
    vector<int> element = {1, 2, 3, 4}, current;
    permutation(element, 0, current);

    for (const auto &vec : vtr) {
        for (int num : vec) {
            cout << num << ' ';
        }
        cout << '\n';
    }

    return 0;
}
