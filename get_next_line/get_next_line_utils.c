#include "get_next_line.h"

static int	findlen(const char *str)
{
	int	scount;

	scount = 0;
	if (str == 0)
		return (0);
	while (*(str + scount))
		scount++;
	return (scount);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		index;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	i = 0;
	index = 0;
	str = malloc((findlen(s1) + findlen(s2) + 1) * sizeof(char));
	if (!str)
		return (0);
	while (s1[index] != '\0')
		str[i++] = s1[index++];
	index = 0;
	while (s2[index] != '\0')
		str[i++] = s2[index++];
	str[i] = '\0';
	free(s1);
	return (str);
}