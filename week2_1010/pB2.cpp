#include <bits/stdc++.h>
using namespace std;

void sol() {
    int n;
    cin >> n;

    // 優先佇列，用來存放山的高度和名稱（高度優先）
    priority_queue<pair<int, string>> pq;

    // 讀入山的名稱和高度
    for (int i = 0; i < n; i++) {
        string name;
        int height;
        cin >> name >> height;
        pq.push({height, name});  // 儲存為 (高度, 名稱)
    }

    // 取出最高的山（忽略）
    pq.pop();

    // 取出第二高的山
    cout << pq.top().second << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    sol();
    return 0;
}
