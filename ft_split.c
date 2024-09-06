#include "libft.h"
static size_t howMany_words(char const *s, char c)
{
    size_t num_of_words;
    size_t j;

    num_of_words = 0;
    j = 0;
    while(s[j] == c)
        j++;
    while(s[j])
    {
        if((!j || s[j - 1] == c) && (s[j] != c))
            num_of_words++;
        j++;
    }
    return (num_of_words);
}

static size_t size_of_word (char const *s, char c, size_t i)
{
    size_t size;

    size = 0;
    while(s[i] && s[i] != c)
    {
        size++;
        i++;
    }
    return (size);
}

void mem_free(char **res)
{
    size_t i;
    while(res[i])
    {
        free(res[i]);
        i++;
    }
    free(res);
}

char    **ft_split(char const *s, char c)
{
    char **res;
    size_t i;
    size_t j;
    size_t k;
    size_t word_size;

    i = 0;
    j = 0;
    res = malloc((howMany_words(s, c) + 1) * sizeof(char *));
    
    if(!res)
    {
        return (NULL);
        mem_free(res);
    }
    while(s[i])
    {
        if(s[i] != c)
        {
            word_size = size_of_word(s, c , i);
            res[j] = malloc((word_size + 1) * sizeof(char));
            if(!res[j])
            {
                mem_free(res);
                return (NULL);
            }
            k = 0;
            while(s[i] && s[i] != c)
                res[j][k++] = s[i++];
            res[j][k] = '\0';
            j++;
        }
        else
            i++;
    }
    res[j] = NULL;
    return (res);
}
int main ()
{
    char **res;
    size_t i;

    res = ft_split("hello!", ' ');
    i = 0;
    while(res[i])
    {
        printf("%s\n", res[i]);
        i++;
    }
    return (0);
}