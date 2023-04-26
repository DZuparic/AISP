#include <stdio.h>

int povrh(int a, int b) {
    if (a == b || b == 0) return 1;
    return povrh(a - 1, b - 1) + povrh(a - 1, b);
}



int main() {

    int a = 10;
    int b = 5;

    printf("%d\n", povrh(a, b));

    return 0;
}