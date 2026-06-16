Лабораторная работа №2

Студент: Воронов Александр (номер: 7)
Вариант: 8
Задание: 23 (Факториал числа с использованием цикла while)
Количество предупреждений: 13(10 уникальных)

Предупреждения -Wall
1. Неиспользуемый параметр функции

Строка: 14
Код:

int unused_param_func(int n, int unused)

Предупреждение:

warning: unused parameter ‘unused’ [-Wunused-parameter]

Объяснение:
Параметр функции объявлен, но не используется внутри тела функции.

2. Неиспользуемая переменная

Строка: 24
Код:

int a = 5;

Предупреждение:

warning: unused variable ‘a’ [-Wunused-variable]

Объяснение:
Переменная объявлена, но не используется.

3. Неиспользуемая переменная (unused-but-set)

Строка: 66
Код:

int arr2[5];

Предупреждение:

warning: variable ‘arr2’ set but not used [-Wunused-but-set-variable]

Объяснение:
Массив изменяется, но его значение не используется.

4. Неиспользуемая переменная

Строка: 65
Код:

int idx = ch;

Предупреждение:

warning: unused variable ‘idx’ [-Wunused-variable]
5. Неиспользуемая переменная (char subscript warning контекст)

Строка: 67
Код:

arr2[ch] = 10;

Предупреждение:

warning: array subscript has type ‘char’ [-Wchar-subscripts]

Объяснение:
Индекс массива имеет тип char, что может приводить к некорректной адресации памяти.

6. Пустое тело if

Строка: 74
Код:

;

Предупреждение:

warning: suggest braces around empty body in an ‘if’ statement [-Wempty-body]
7. Сравнение знаковых и беззнаковых типов

Строка: 78
Код:

if (u > n)

Предупреждение:

warning: comparison of integer expressions of different signedness [-Wsign-compare]
8. Предупреждение о приоритетах операций

Строка: 100
Код:

int c = a + b << 1;

Предупреждение:

warning: suggest parentheses around ‘+’ inside ‘<<’ [-Wparentheses]
9. Неиспользуемая переменная

Строка: 113
Код:

int crash = 10 / zero;

Предупреждение:

warning: unused variable ‘crash’ [-Wunused-variable]
10. Подозрительная индентация (misleading indentation)

Строка: 117
Код:

if (n > 0)
    printf("OK\n");
    printf("always\n");

Предупреждение:

warning: this ‘if’ clause does not guard... [-Wmisleading-indentation]
11. Неиспользуемая переменная

Строка: 104
Код:

int bad_size = sizeof(ptr + 1);

Предупреждение:

warning: unused variable ‘bad_size’ [-Wunused-variable]
12. Неиспользуемая переменная

Строка: 91
Код:

int size = sizeof(x);

Предупреждение:

warning: unused variable ‘size’ [-Wunused-variable]
13. Неиспользуемая функция

Строка: 11
Код:

static void unused_func() {}

Предупреждение:

warning: ‘unused_func’ defined but not used [-Wunused-function]