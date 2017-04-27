#include <stdio.h>

int main() {
    int a=0;
    a++;
    int *ptr=&a;
    printf("%d %d", a, *ptr);
    return 0;
}