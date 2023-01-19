#include "so_long.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int ft_strchr(char *s, char c)
{
	int	i;
    int count;

    count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			count++;
		i++;
	}
	return (count);
}

int	ft_diff(char *s1, char *s2)
{
	int	i;
	int	j;

	i = -1;
	while (s1[++i])
	{
		j = -1;
		while (s2[++j])
		{
			if (s1[i] == s2[j])
				break;
		}
		if (s2[j] == '\0')
			return (0);
	}
	return (1);
}

char **ft_multi_arr(t_map *map)
{
	char **str;
	int     i;

    i = -1;
    str = (char **)malloc((map->heigth + 1) * sizeof(char *));
    if (str == NULL)
        return (0);
    str[map->heigth] = 0;
    while (++i < map->heigth)
    {
        str[i] = malloc((map->width + 1)* sizeof(char));
        str[i][map->width] = '\0';
    }
	return (str);
}

void	ft_memset(char	*b, char c, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		b[i] = c;
		i++;
	}
}