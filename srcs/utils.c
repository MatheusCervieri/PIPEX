#include "pipex.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	if (n == 0)
		return (0);
	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
		i++;
	}
	return (0);
}

char *join_bar(char *s1, char *s2)
{
	size_t	newstrlen;
	char	*newstr;
	char	*newstrfirstposition;

	newstrlen = ft_strlen(s1) + ft_strlen(s2);
	newstr = malloc(newstrlen * sizeof(char) + 2);
	if (!newstr)
		return (NULL);
	newstrfirstposition = newstr;
	while (*s1 != '\0')
	{
		*newstr = *s1;
		newstr++;
		s1++;
	}
	*newstr = '/';
	newstr++;
	while (*s2 != '\0')
	{
		*newstr = *s2;
		newstr++;
		s2++;
	}
	*newstr = '\0';

	return (newstrfirstposition);
}

