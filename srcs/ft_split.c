#include "pipex.h"

static unsigned int	count_words(const char *s, char split_char)
{
	unsigned int	words;

	words = 0;
	if (*s == '\0')
		return (words);
	if (split_char == '\0')
		return (1);
	while (*s == split_char && *s)
		s++;
	while (*s != '\0')
	{
		words++;
		while (*s != split_char && *s != '\0')
		{
			s++;
		}
		while (*s == split_char && *s != '\0')
		{
			s++;
		}
	}
	return (words);
}

static void	*free_words(char **words)
{
	while (*words)
		free(*words);
	free(words);
	return (NULL);
}

static char	**put_words(char **words, const char *s, char split_char)
{
	unsigned int	i;
	unsigned int	length;

	i = 0;
	while (*s != '\0')
	{
		length = 0;
		while (s[length] != split_char && s[length] != '\0')
			length++;
		words[i] = malloc (sizeof(char) * length + 1);
		if (!words[i])
			free_words(words);
		words[i][length] = '\0';
		while (length > 0)
		{
			words[i][length - 1] = s[length - 1];
			length--;
		}
		while (*s != split_char && *s)
			s++;
		while (*s == split_char && *s)
			s++;
		i++;
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char			**words;
	unsigned int	words_amount;

	words_amount = count_words(s, c);
	words = (char **) malloc(sizeof(char *) * (words_amount + 1));
	if (!words)
		return (NULL);
	while (*s == c && *s != '\0')
		s++;
	words = put_words(words, s, c);
	words[words_amount] = NULL;
	return (words);
}