#include <iostream>
#include <vector>
using namespace std;

string can_empty_piles(long long a, long long b) {
    // 檢查條件
    if ((a + b) % 3 == 0 && min(a, b) * 2 >= max(a, b)) {
        return "YES";
    }
    return "NO";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    vector<string> results(t);

    // 處理每組測試數據
    for (int i = 0; i < t; ++i) {
        long long a, b;
        cin >> a >> b;
        results[i] = can_empty_piles(a, b);
    }

    // 一次性輸出所有結果
    for (const string& result : results) {
        cout << result << "\n";
    }

    return 0;
}
