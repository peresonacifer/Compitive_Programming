#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {

    srand(time(NULL));
    for(unsigned int i = 1; i <= 20; i++) {
        printf("%10d", 1 + rand() % 5);

        if(!(i % 5)) {
            puts("");
        }
    }
    
    return 0;
}