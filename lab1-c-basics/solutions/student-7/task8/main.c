#include <stdio.h>

int main() {
    int a, b;

    printf("Введите два числа: ");
    scanf("%d %d", &a, &b);

    // Алгоритм Евклида
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }

    printf("НОД = %d\n", a);

    return 0;
}