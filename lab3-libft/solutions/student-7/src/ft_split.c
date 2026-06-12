#include "libft.h"

static size_t count_words(char const *s, char c)
{
    size_t count;
    int in_word;

    count = 0;
    in_word = 0;
    while (*s)
    {
        if (*s != c && !in_word)
        {
            in_word = 1;
            count++;
        }
        else if (*s == c)
            in_word = 0;
        s++;
    }
    return (count);
}

static char *copy_word(char const *start, size_t length)
{
    char *word;
    size_t i;

    word = malloc(length + 1);
    if (!word)
        return (NULL);
    i = 0;
    while (i < length)
    {
        word[i] = start[i];
        i++;
    }
    word[i] = '\0';
    return (word);
}

static char **free_words(char **words, size_t used)
{
    size_t i;

    i = 0;
    while (i < used)
    {
        free(words[i]);
        i++;
    }
    free(words);
    return (NULL);
}

char **ft_split(char const *s, char c)
{
    char **result;
    size_t words;
    size_t i;
    size_t len;

    if (!s)
        return (NULL);
    words = count_words(s, c);
    result = malloc(sizeof(char *) * (words + 1));
    if (!result)
        return (NULL);
    i = 0;
    while (*s)
    {
        if (*s != c)
        {
            len = 0;
            while (s[len] && s[len] != c)
                len++;
            result[i] = copy_word(s, len);
            if (!result[i])
                return (free_words(result, i));
            i++;
            s += len;
        }
        else
            s++;
    }
    result[i] = NULL;
    return (result);
}
