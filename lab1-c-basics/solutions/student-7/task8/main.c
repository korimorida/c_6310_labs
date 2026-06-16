#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b;

    printf("Введите два целых числа: ");

    int result = scanf("%d %d", &a, &b);
    if (result != 2) {
        printf("Ошибка: нужно ввести ровно два целых числа.\n");
        return 1;
    }

    a = abs(a);
    b = abs(b);

    if (a == 0 && b == 0) {
        printf("Ошибка: НОД для 0 и 0 не определён.\n");
        return 1;
    }

    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }

    printf("НОД = %d\n", a);

    return 0;
}