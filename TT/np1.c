// #include<stdio.h>

// void func(int a[][2]) {
//     int temp;
//     temp = a[0][1];
//     a[0][1] = a[1][1];
//     a[1][1] = temp;
// }

// int main() {
//     int a[2][2] = {{2, 1}, {1, 2}};  
//     printf("%d %d\n", a[0][1], a[1][1]);
//     func(a);
//     printf("%d %d\n", a[0][1], a[1][1]);
//     return 0;
// }
#include <stdio.h>

void func(int a[][2]) {
    printf("Inside func: a = %p\n", a);
    printf("Inside func: &a[0][0] = %p\n", &a[0][0]);
}

int main() {
    int a[2][2] = {{2, 1}, {1, 2}};
    printf("In main: a = %p\n", a);
    printf("In main: &a[0][0] = %p\n", &a[0][0]);
    func(a);
    return 0;
}
