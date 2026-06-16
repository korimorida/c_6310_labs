#include <stdio.h>

int main() {
    int n;
    const int MAX = 20;
    unsigned long long factorial = 1;

    do {
        printf("Введите число (0-%d): ", MAX);

        if (scanf("%d", &n) != 1) {
            printf("Ошибка: некорректный ввод.\n");

            while (getchar() != '\n');
            n = -1;
            continue;
        }

        if (n < 0 || n > MAX) {
            printf("Ошибка: число должно быть от 0 до %d.\n", MAX);
        }

    } while (n < 0 || n > MAX);

    int i = 1;
    while (i <= n) {
        factorial *= i;
        i++;
    }

    printf("Факториал %d = %llu\n", n, factorial);

    return 0;
}