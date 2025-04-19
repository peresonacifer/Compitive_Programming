#include <stdio.h>

void sol(int n, int ans[], int pos) {
    int ar[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &ar[i]);
    }
    for(int i = 0; i < n; i++) {
        ans[pos]++;
        for(int j = i + 1; j < n; j++) {
            if(ar[j] >= ar[j - 1]) {
                ans[pos]++;
            }
            else {
                break;
            }
        }
    }
}
int main() {
    int t;
    int result[t];
    scanf("%d", &t);
    int pos = 0;
    for(int i = 0; i < t; i++) {
        int n;
        scanf("%d", &n);
        result[i] = 0;
        sol(n, result, pos);
        pos++;
    }

    for(int i = 0; i < t; i++) {
        printf("%d\n", result[i]);
    }

    return 0;
}
    
/*
#include <stdio.h>

void sol(int n, int *ans) {
    int ar[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &ar[i]);
    }

    int count = 1; // 单个元素的子数组
    for (int i = 1; i < n; i++) {
        if (ar[i] >= ar[i - 1]) {
            count++; // 扩展当前非递减子数组长度
        } else {
            *ans += (count * (count + 1)) / 2; // 累计当前非递减子数组数量
            count = 1; // 重新开始计算
        }
    }
    *ans += (count * (count + 1)) / 2; // 累计最后一段非递减子数组数量
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n, result = 0;
        scanf("%d", &n);
        sol(n, &result);
        printf("%d\n", result);
    }

    return 0;
}

*/