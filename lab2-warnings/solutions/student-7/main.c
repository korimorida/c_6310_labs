/*

Лабораторная работа №2
Студент: Воронов Александр (номер: 7)
Вариант: 8
Задание: 23 (Факториал числа с использованием цикла while)
Количество предупреждений: 13 */

#include <stdio.h>

static void unused_func() {} // Wunused-function

int call_undeclared_func(int n); // Wimplicit-function-declaration

int factorial(int n) {
    int i, res = 1;
    for (i = 1; i <= n; i++)
        res *= i;
    return res;
}

// 10. Wreturn-type — отсутствие return
int no_return_function() {
    int a = 5; // функция должна возвращать int, но return нет
}

int main() {
    int n; // Wunused-variable
    unsigned long long result = 1;

    printf("Введите число: ");
    scanf("%d", &n);

    if (n < 0)
        ; // Wempty-body

    int x;


    unsigned int u = 5;
    if (u > n) {} // Wsign-compare

    char arr[10];
    arr['a'] = 42; // Wchar-subscripts

    unsigned char uc = 5;
    char *p = &uc; // Wpointer-sign

    if (n > 0)
  

    result = call_undeclared_func(n); // Wimplicit-function-declaration

    // 11. Wparentheses — отсутствие скобок
    int y = 5 + 3 * 2; // при -Wall даст предупреждение о скобках

    // 12. Wsizeof-pointer-memaccess
    int *ptr = &n;
    int size = sizeof(*ptr + 1); // sizeof с указателем

    printf("Факториал %d = %llu\n", n, factorial(n));

    return 0;
}

// определяем функцию после main
int call_undeclared_func(int n) {
    return n;
}