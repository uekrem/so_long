#include "so_long.h"

int	ft_multi_strlen(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_calc(long tmp)
{
	int		len;

	len = 0;
	if (tmp < 0)
	{
		tmp *= -1;
		len++;
	}
	else if (tmp == 0)
		return (1);
	while (tmp > 0)
	{
		len++;
		tmp /= 10;
	}
	return (len);
}

void	ft_print(char *p, int len, int i, long tmp)
{
	if (tmp < 0)
	{
		p[i] = '-';
		tmp *= -1;
		i++;
	}
	while (i <= len)
	{
		p[len] = tmp % 10 + '0';
		tmp /= 10;
		len--;
	}
}

char	*ft_itoa(int n)
{
	long	tmp;
	int		len;
	char	*p;
	int		i;

	i = 0;
	tmp = n;
	len = ft_calc(tmp);
	p = malloc(sizeof(char) * (len + 1));
	if (!p)
		return (0);
	p[len] = '\0';
	len--;
	if (tmp == 0)
	{
		p[len] = tmp + '0';
		return (p);
	}
	ft_print(p, len, i, tmp);
	return (p);
}