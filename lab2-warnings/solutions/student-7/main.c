/*
Лабораторная работа №2
Студент: Воронов Александр (номер: 7)
Вариант: 8
Задание: 23 (Факториал числа с использованием цикла while)
*/

#include <stdio.h>

// Wunused-function
static void unused_func() {}

// Wunused-parameter
int unused_param_func(int n, int unused) {
    return n;
}

// Wimplicit-function-declaration (будет предупреждение при вызове без include/прототипа)
int call_undeclared_func(int n);
int fake_math(void);

// Wreturn-type
int no_return_function() {
    int a = 5; // Wunused-variable
}

// нормальный факториал
unsigned long long safe_factorial(int n) {
    unsigned long long res = 1;
    int i = 1;

    while (i <= n) {
        res *= i;
        i++;
    }

    return res;
}

int call_undeclared_func(int n) {
    return n;
}

int fake_math(void) {
    return 42;
}

int main() {

    int n;
    unsigned long long result = 1;

    printf("Введите число (0-20): ");

    if (scanf("%d", &n) != 1) {
        printf("Ошибка ввода\n");
        return 1;
    }

    if (n < 0 || n > 20) {
        printf("Ошибка: допустимый диапазон 0-20\n");
        return 1;

        char ch = 'a';
        int idx = ch;      // char → используется как индекс (warning)
        int arr2[5];
        arr2[ch] = 10;     // <- это гарантированный Wchar-subscripts
    }

    /* ================= WARNING-БЛОКИ ================= */

    // Wempty-body
    if (n < 0)
        ;

    // Wsign-compare
    unsigned int u = 5;
    if (u > n) {}

    // Wchar-subscripts
    char arr[10];
    arr['a' % 10] = 42;

    // Wpointer-sign
    unsigned char uc = 5;
    char *p = (char *)&uc;

    // Wunused-variable
    int x = 10;
    int y = 20;
    int size = sizeof(x);

    // Wimplicit-function-declaration (если убрать прототип выше)
    result = call_undeclared_func(n);
    fake_math();

    // Wparentheses
    int a = 1;
    int b = 2;
    int c = a + b << 1;

    // Wsizeof-pointer-memaccess
    int *ptr = &n;
    int bad_size = sizeof(ptr + 1);

    // Wuninitialized
    int bad;
    if (bad > 0) {}

    // Wdiv-by-zero (не выполняется, но warning-логика есть)
    int zero = 0;
    if (zero) {
        int crash = 10 / zero;
    }

    // Wmisleading-indentation
    if (n > 0)
        printf("OK(для варнинга)\n");
        printf("always(для варнинга)\n");

    // Wunused-but-set-variable
    result = result;

    printf("Факториал %d = %llu\n", n, safe_factorial(n));

    return 0;
}