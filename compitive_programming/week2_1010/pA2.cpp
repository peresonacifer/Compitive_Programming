#include <cstdio>
#include <cstring>

void sol() {
    char s[101];
    scanf("%s", s);  // 使用 scanf 讀取輸入，避免 C++ 流的額外開銷
    int n = strlen(s);

    bool allUpper = true;
    for (int i = 1; i < n; ++i) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            allUpper = false;
            break;
        }
    }

    if (allUpper) {
        for (int i = 0; i < n; ++i) {
            if (s[i] >= 'a' && s[i] <= 'z')
                s[i] = s[i] - 'a' + 'A';  // 小寫轉大寫
            else
                s[i] = s[i] - 'A' + 'a';  // 大寫轉小寫
        }
    }

    printf("%s\n", s);  // 使用 printf 輸出結果
}

int main() {
    sol();
    return 0;
}
