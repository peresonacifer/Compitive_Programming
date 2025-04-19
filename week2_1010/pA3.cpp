#include <bits/stdc++.h>
#include <cctype>

using namespace std;

void sol() {
    string s;
    cin >> s;

    // 檢查是否全部字母都是大寫或只有第一個是小寫其餘是大寫
    if (all_of(s.begin() + 1, s.end(), ::isupper)) {
        for (char& c : s) {
            c = isupper(c) ? tolower(c) : toupper(c);
        }
    }
    cout << s;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    sol();
    return 0;
}
