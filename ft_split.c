#include "libft.h"

static size_t	how_many_words(char const *s, char c)
{
	size_t	num_of_words;
	size_t	j;

	num_of_words = 0;
	j = 0;
	while (s[j] == c)
		j++;
	while (s[j])
	{
		if ((!j || s[j - 1] == c) && (s[j] != c))
			num_of_words++;
		j++;
	}
	return (num_of_words);
}

static size_t	size_of_word(char const *s, char c, size_t i)
{
	size_t	size;

	size = 0;
	while (s[i] && s[i] != c)
	{
		size++;
		i++;
	}
	return (size);
}

char	*alloc_cpy(char *s, char c, t_intialValues *ptr_to)
{
	char	*res;
	size_t	i;

	i = 0;
	ptr_to->word_size = size_of_word(s, c, ptr_to->i);
	res = malloc((ptr_to->word_size + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (s[ptr_to->i] && s[ptr_to->i] != c)
		res[i++] = s[ptr_to->i++];
	res[i] = '\0';
	return (res);
}

static void	mem_free(char **res, size_t j)
{
	size_t	i;

	i = 0;
	while (i < j)
	{
		free(res[i]);
		i++;
	}
	free(res);
}

char	**ft_split(char const *s, char c)
{
	char			**res;
	t_intialValues	ptr_to;

	ptr_to.i = 0;
	ptr_to.j = 0;
	res = malloc((how_many_words(s, c) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	while (s[ptr_to.i])
	{
		if (s[ptr_to.i] != c)
		{
			res[ptr_to.j] = alloc_cpy((char *)s, c, &ptr_to);
			if (!res[ptr_to.j])
			{
				mem_free(res, ptr_to.j);
				return (NULL);
			}
			ptr_to.j++;
		}
		else
			ptr_to.i++;
	}
	res[ptr_to.j] = NULL;
	return (res);
}
// int main ()
// {
//     char **res;
//     size_t i;

//     res = ft_split("hello!", ' ');
//     i = 0;
//     while(res[i])
//     {
//         printf("%s\n", res[i]);
//         i++;
//     }
//     return (0);
// }
