#include<stdio.h>

void print_digit(int num, char *ar, int *pos) {
    if(num < 10) {
        ar[(*pos)++] = num + '0';
        return;
    }
    print_digit(num / 10, ar, pos);
    ar[(*pos)++] = ' ';
    ar[(*pos)++] = num % 10 + '0';
}
int main() {
    int t;
    scanf("%d", &t);
    char ans[100];
    int pos = 0;
    while(t--) {
        int num;
        scanf("%d", &num);
        print_digit(num, ans, &pos);
        ans[pos++] = '\n';
    }
    ans[pos] = '\0';
    printf("%s", ans);

    return 0;
}