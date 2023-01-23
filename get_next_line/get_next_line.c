/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekrem <hekrem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:52:23 by hekrem            #+#    #+#             */
/*   Updated: 2023/01/23 15:17:56 by hekrem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_line(int fd, char *arr)
{
	char	*buff;
	int		read_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	read_bytes = 1;
	while (read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_bytes] = '\0';
		arr = ft_strjoin(arr, buff);
	}
	free(buff);
	return (arr);
}

char	*get_next_line(int fd)
{
	static char	*arr;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	arr = read_line(fd, arr);
	if (!arr)
		return (NULL);
	return (arr);
}
