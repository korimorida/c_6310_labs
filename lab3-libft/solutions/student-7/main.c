#include "inc/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

static int tests_total = 0;
static int tests_failed = 0;

static void print_test(const char *name, int ok)
{
    tests_total++;
    if (ok)
        printf("[OK]   %s\n", name);
    else
    {
        printf("[FAIL] %s\n", name);
        tests_failed++;
    }
}

static char *capture_fd_output(void (*fn)(int))
{
    char buf[128];
    ssize_t n;
    char *result;
    size_t len;
    int pipefd[2];

    if (pipe(pipefd) == -1)
        return (NULL);
    fn(pipefd[1]);
    close(pipefd[1]);
    result = malloc(1);
    if (!result)
    {
        close(pipefd[0]);
        return (NULL);
    }
    result[0] = '\0';
    len = 0;
    while ((n = read(pipefd[0], buf, sizeof(buf))) > 0)
    {
        char *tmp = realloc(result, len + n + 1);
        if (!tmp)
        {
            free(result);
            close(pipefd[0]);
            return (NULL);
        }
        result = tmp;
        memcpy(result + len, buf, n);
        len += n;
        result[len] = '\0';
    }
    close(pipefd[0]);
    return (result);
}

static void free_split(char **parts)
{
    size_t i;

    if (!parts)
        return;
    i = 0;
    while (parts[i])
    {
        free(parts[i]);
        i++;
    }
    free(parts);
}

static char add_index(unsigned int i, char c)
{
    return (char)(c + i);
}

static void to_upper_at(unsigned int i, char *c)
{
    (void)i;
    if (c && *c >= 'a' && *c <= 'z')
        *c = *c - 'a' + 'A';
}

static void putchar_helper(int fd)
{
    ft_putchar_fd('X', fd);
}

static void putstr_helper(int fd)
{
    ft_putstr_fd("Hi", fd);
}

static void putendl_helper(int fd)
{
    ft_putendl_fd("OK", fd);
}

static void putnbr_helper(int fd)
{
    ft_putnbr_fd(-42, fd);
}

static void inc_int(void *content)
{
    if (content)
        (*(int *)content) += 1;
}

static void *duplicate_string(void *content)
{
    if (!content)
        return (NULL);
    return ft_strdup((char *)content);
}

static void test_char_functions(void)
{
    print_test("ft_isalpha letters", ft_isalpha('A') && ft_isalpha('z'));
    print_test("ft_isalpha non-letter", !ft_isalpha('0'));
    print_test("ft_isdigit digits", ft_isdigit('0') && ft_isdigit('9'));
    print_test("ft_isdigit non-digit", !ft_isdigit('a'));
    print_test("ft_isalnum alnum", ft_isalnum('A') && ft_isalnum('8'));
    print_test("ft_isalnum non-alnum", !ft_isalnum('$'));
    print_test("ft_isascii ascii", ft_isascii(127));
    print_test("ft_isascii non-ascii", !ft_isascii(128));
    print_test("ft_isprint printable", ft_isprint(' '));
    print_test("ft_isprint non-printable", !ft_isprint('\n'));
    print_test("ft_toupper lower", ft_toupper('a') == 'A');
    print_test("ft_toupper upper unchanged", ft_toupper('A') == 'A');
    print_test("ft_tolower upper", ft_tolower('A') == 'a');
    print_test("ft_tolower lower unchanged", ft_tolower('a') == 'a');
    print_test("ft_isspace space", ft_isspace(' '));
    print_test("ft_isspace tab", ft_isspace('\t'));
    print_test("ft_isspace non-space", !ft_isspace('A'));
}

static void test_string_search(void)
{
    const char *sample = "Hello, libft!";
    char *res1 = ft_strchr(sample, 'l');
    char *res2 = strchr(sample, 'l');

    print_test("ft_strchr finds char", res1 && res2 && res1 - sample == res2 - sample);

    res1 = ft_strrchr(sample, 'l');
    res2 = strrchr(sample, 'l');
    print_test("ft_strrchr finds last char", res1 && res2 && res1 - sample == res2 - sample);

    print_test("ft_strlen matches strlen", ft_strlen(sample) == strlen(sample));
    print_test("ft_strncmp equal", ft_strncmp("abc", "abc", 3) == 0);
    print_test("ft_strncmp diff", ft_strncmp("abc", "abd", 3) < 0);

    res1 = ft_strnstr("Hello world", "world", 11);
    print_test("ft_strnstr finds substring", res1 && res1 - "Hello world" == 6);
    print_test("ft_strnstr no result when too short", ft_strnstr("Hello world", "world", 5) == NULL);
}

static void test_memory_and_conversion(void)
{
    int *zeroed = ft_calloc(4, sizeof(int));
    if (zeroed)
    {
        int ok = zeroed[0] == 0 && zeroed[3] == 0;
        print_test("ft_calloc returns zeroed memory", ok);
        free(zeroed);
    }
    else
        print_test("ft_calloc returns non-NULL", 0);

    char *dup = ft_strdup("libft");
    print_test("ft_strdup copies string", dup && strcmp(dup, "libft") == 0);
    free(dup);

    char *sub = ft_substr("012345", 2, 3);
    print_test("ft_substr extracts substring", sub && strcmp(sub, "234") == 0);
    free(sub);

    char *joined = ft_strjoin("foo", "bar");
    print_test("ft_strjoin concatenates", joined && strcmp(joined, "foobar") == 0);
    free(joined);

    char *trimmed = ft_strtrim("  abc  ", " ");
    print_test("ft_strtrim removes chars", trimmed && strcmp(trimmed, "abc") == 0);
    free(trimmed);

    char **parts = ft_split(" a  b ", ' ');
    print_test("ft_split creates correct parts", parts && parts[0] && strcmp(parts[0], "a") == 0 && parts[1] && strcmp(parts[1], "b") == 0 && parts[2] == NULL);
    free_split(parts);

    char *itoa_min = ft_itoa(INT_MIN);
    print_test("ft_itoa INT_MIN", itoa_min && strcmp(itoa_min, "-2147483648") == 0);
    free(itoa_min);

    char *itoa_max = ft_itoa(INT_MAX);
    print_test("ft_itoa INT_MAX", itoa_max && strcmp(itoa_max, "2147483647") == 0);
    free(itoa_max);

    char *mapped = ft_strmapi("abc", add_index);
    if (mapped)
    {
        print_test("ft_strmapi applies function", strcmp(mapped, "ace") == 0);
        free(mapped);
    }
    else
        print_test("ft_strmapi returns non-NULL", 0);

    char str[] = "abc";
    ft_striteri(str, to_upper_at);
    print_test("ft_striteri modifies string in place", strcmp(str, "ABC") == 0);
}

static void test_put_fd(void)
{
    char *output;

    output = capture_fd_output(putchar_helper);
    print_test("ft_putchar_fd writes char", output && strcmp(output, "X") == 0);
    free(output);

    output = capture_fd_output(putstr_helper);
    print_test("ft_putstr_fd writes string", output && strcmp(output, "Hi") == 0);
    free(output);

    output = capture_fd_output(putendl_helper);
    print_test("ft_putendl_fd writes line", output && strcmp(output, "OK\n") == 0);
    free(output);

    output = capture_fd_output(putnbr_helper);
    print_test("ft_putnbr_fd writes number", output && strcmp(output, "-42") == 0);
    free(output);
}

static void test_string_copy_and_concat(void)
{
    char dst[16];
    size_t ret;

    ret = ft_strlcpy(dst, "hello", sizeof(dst));
    print_test("ft_strlcpy copies properly", ret == 5 && strcmp(dst, "hello") == 0);

    strcpy(dst, "hi");
    ret = ft_strlcat(dst, "world", sizeof(dst));
    print_test("ft_strlcat appends properly", ret == 7 && strcmp(dst, "hiworld") == 0);
}

static void test_memory_copy(void)
{
    char buffer[8] = "1234567";
    ft_bzero(buffer + 2, 3);
    print_test("ft_bzero zeroes memory", buffer[2] == 0 && buffer[3] == 0 && buffer[4] == 0);

    char src[8] = "abcdef";
    char dst[8];
    ft_memcpy(dst, src, 4);
    dst[4] = '\0';
    print_test("ft_memcpy copies data", strcmp(dst, "abcd") == 0);

    char overlap[10] = "012345678";
    ft_memmove(overlap + 2, overlap, 5);
    print_test("ft_memmove handles overlap", strcmp(overlap, "010123478") == 0);
}

static void test_list_functions(void)
{
    t_list *list = NULL;
    t_list *mapped = NULL;
    t_list *node;
    int *first = malloc(sizeof(int));
    int *second = malloc(sizeof(int));
    int *third = malloc(sizeof(int));

    if (!first || !second || !third)
        exit(EXIT_FAILURE);
    *first = 1;
    *second = 2;
    *third = 3;

    ft_lstadd_back(&list, ft_lstnew(first));
    ft_lstadd_back(&list, ft_lstnew(second));
    ft_lstadd_front(&list, ft_lstnew(third));

    print_test("ft_lstsize counts nodes", ft_lstsize(list) == 3);
    print_test("ft_lstlast returns last", ft_lstlast(list) && ft_lstlast(list)->content == second);

    ft_lstiter(list, inc_int);
    print_test("ft_lstiter applies function", *first == 2 && *second == 3 && *third == 4);

    node = ft_lstnew(ft_strdup("map"));
    mapped = ft_lstmap(node, duplicate_string, free);
    print_test("ft_lstmap creates mapped list", mapped && mapped->content && strcmp((char *)mapped->content, "map") == 0);

    ft_lstdelone(node, free);
    ft_lstclear(&mapped, free);
    ft_lstclear(&list, free);
    print_test("ft_lstclear empties list", list == NULL);
}

int main(void)
{
    test_char_functions();
    test_string_search();
    test_memory_and_conversion();
    test_put_fd();
    test_string_copy_and_concat();
    test_memory_copy();
    test_list_functions();

    printf("\nTotal tests: %d\n", tests_total);
    printf("Passed: %d\n", tests_total - tests_failed);
    printf("Failed: %d\n", tests_failed);
    return (tests_failed != 0);
}
