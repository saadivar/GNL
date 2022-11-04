/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 22:45:46 by sel-biyy          #+#    #+#             */
/*   Updated: 2022/11/03 22:29:36 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	int		i;
	int		mid;

	if (!s1 || !s2)
		return (0);
	p = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!(p))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	mid = i;
	i = 0;
	while (s2[i])
	{
		p[mid + i] = s2[i];
		i++;
	}
	p[mid + i] = '\0';
	free(s1);
	return (p);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*p;
	size_t	i;

	i = 0;
	if (count && size > SIZE_MAX / count)
		return (0);
	p = malloc(count * size);
	if (!(p))
		return (NULL);
	while (i < count * size)
	{
		p[i] = '\0';
		i++;
	}
	return ((void *)p);
}
