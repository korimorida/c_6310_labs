# Отчет о предупреждениях

**Студент:** Воронов Александр (номер: 7)  
**Вариант:** 8  
**Задание:** 23 (Факториал числа с использованием цикла while)  
**Количество предупреждений:** 13  

---

## Предупреждения -Wall

---

1. Неиспользуемая переменная
Строка: 24  
Код:
```c
int a = 5;

Текст предупреждения:

warning: unused variable ‘a’ [-Wunused-variable]

Объяснение:
Переменная объявлена и инициализирована, но нигде не используется в программе.

2. Отсутствие фигурных скобок / пустое тело if

Строка: 35
Код:

if (n < 0)
    ;

Текст предупреждения:

warning: suggest braces around empty body in an ‘if’ statement [-Wempty-body]

Объяснение:
Условный оператор содержит пустое тело, что может привести к ошибкам чтения кода.

3. Сравнение знаковых и беззнаковых типов

Строка: 41
Код:

if (u > n)

Текст предупреждения:

warning: comparison of integer expressions of different signedness [-Wsign-compare]

Объяснение:
Происходит сравнение unsigned и signed типов данных.

4. Несоответствие знаковости указателей

Строка: 47
Код:

char *p = &uc;

Текст предупреждения:

warning: pointer targets in initialization differ in signedness [-Wpointer-sign]

Объяснение:
Указатель типа char* получает адрес unsigned char*.

5. Несоответствие формата вывода

Строка: 61
Код:

printf("Факториал %d = %llu\n", n, factorial(n));

Текст предупреждения:

warning: format ‘%llu’ expects argument of type ‘long long unsigned int’, but argument has type ‘int’ [-Wformat=]

Объяснение:
Тип возвращаемого значения функции не соответствует формату вывода.

6. Неиспользуемая переменная

Строка: 59
Код:

int size = sizeof(*ptr + 1);

Текст предупреждения:

warning: unused variable ‘size’ [-Wunused-variable]

Объяснение:
Переменная объявлена, но не используется.

7. Неиспользуемая переменная

Строка: 55
Код:

int y = 5 + 3 * 2;

Текст предупреждения:

warning: unused variable ‘y’ [-Wunused-variable]

Объяснение:
Переменная вычисляется, но не используется.

8. Неиспользуемая переменная (указатель)

Строка: 47
Код:

char *p = &uc;

Текст предупреждения:

warning: unused variable ‘p’ [-Wunused-variable]

Объяснение:
Указатель объявлен, но не используется.

9. Неиспользуемый массив

Строка: 43
Код:

char arr[10];

Текст предупреждения:

warning: variable ‘arr’ set but not used [-Wunused-but-set-variable]

Объяснение:
Массив изменяется, но не используется в дальнейшем.

10. Неиспользуемая переменная

Строка: 37
Код:

int x;

Текст предупреждения:

warning: unused variable ‘x’ [-Wunused-variable]

Объяснение:
Переменная объявлена, но не используется.

11. Неиспользуемая переменная

Строка: 29
Код:

unsigned long long result = 1;

Текст предупреждения:

warning: variable ‘result’ set but not used [-Wunused-but-set-variable]

Объяснение:
Переменная присваивается, но не используется.

12. Отсутствие return в функции

Строка: 25
Код:

int no_return_function() { }

Текст предупреждения:

warning: control reaches end of non-void function [-Wreturn-type]

Объяснение:
Функция объявлена как возвращающая int, но return отсутствует.

13. Неиспользуемая функция

Строка: 11
Код:

static void unused_func() {}

Текст предупреждения:

warning: ‘unused_func’ defined but not used [-Wunused-function]

Объяснение:
Функция определена, но ни разу не вызывается в программе.