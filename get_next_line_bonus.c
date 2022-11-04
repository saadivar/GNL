/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 19:10:23 by sel-biyy          #+#    #+#             */
/*   Updated: 2022/11/04 14:00:07 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*refresh(char *holder)
{
	char	*afternl;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (holder[i] && holder[i] != '\n')
		i++;
	if (!holder[i])
	{
		free(holder);
		return (NULL);
	}
	afternl = malloc((ft_strlen(holder) - i + 1) * sizeof(char));
	if (!afternl)
		return (NULL);
	i++;
	while (holder[i])
		afternl[j++] = holder[i++];
	afternl[j] = '\0';
	free(holder);
	return (afternl);
}

char	*linereturned(char *holder)
{
	int		i;
	char	*s;

	i = 0;
	if (!holder[i])
		return (NULL);
	while (holder[i] && holder[i] != '\n')
		i++;
	s = (char *)malloc(sizeof(char) * (i + 2));
	if (!s)
		return (NULL);
	i = 0;
	while (holder[i] && holder[i] != '\n')
	{
		s[i] = holder[i];
		i++;
	}
	if (holder[i] == '\n')
	{
		s[i] = holder[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_read_and_hold(int fd, char *holder)
{
	char	*buff;
	int		read_bytes;

	if (!holder)
		holder = ft_calloc(1, 1);
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(holder, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buff);
			free(holder);
			return (NULL);
		}
		buff[read_bytes] = '\0';
		holder = ft_strjoin(holder, buff);
	}
	free(buff);
	return (holder);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*holder[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	holder[fd] = ft_read_and_hold(fd, holder[fd]);
	if (!holder[fd])
		return (NULL);
	line = linereturned(holder[fd]);
	holder[fd] = refresh(holder[fd]);
	return (line);
}

// int main ()
// {
// int i = open("get_next_line_bonus.h",O_RDONLY);
// int y = open("get_next_line.h",O_RDONLY);
// char *file1 = get_next_line(i);
// char *file2 = get_next_line(y);
// while (file1 && file2)
// {
// 	printf("%s", file1);
// 	printf("%s", file2);
// 	free(file1);
// 	free(file2);
// 	file1 = get_next_line(i);
// 	file2 = get_next_line(y);
// }
// }
