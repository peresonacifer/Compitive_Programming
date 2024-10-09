#include <bits/stdc++.h>

int my_sort(int digits, int n, int s[1000000]) {
    int times = 0;
    while(digits < n) {
        for(int i = digits; i > 0; i--) {
            if(s[i] < s[i - 1]) {
                int temp = s[i];
                s[i] = s[i - 1];
                s[i - 1] = temp;
                times ++;
            }
            else break;
        }
        digits++;
    }
    
    return times;
}

int main(void) {

    int n;

    std::cin>>n;
    
    int array[n];
    
    for(int i = 0; i < n; i++) {
        std::cin>>array[i];
    }
    
    std::cout<<my_sort(1, n, array)<<"\n";
    
    return 0;
}