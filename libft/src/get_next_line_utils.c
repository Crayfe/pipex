/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayuso-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:31:19 by cayuso-f          #+#    #+#             */
/*   Updated: 2024/10/04 14:21:01 by cayuso-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

/*	AUXILIAR FUNCTIONS	*/
void	*gnl_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*aux_s;

	i = 0;
	aux_s = (unsigned char *)s;
	while (i < n)
		aux_s[i++] = c;
	return (s);
}

size_t	gnl_strlen(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] != c)
		i++;
	return (i);
}

char	*gnl_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)s + i);
	return (0);
}

char	*gnl_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	aux_len;
	size_t	i;

	if (!s)
		return (0);
	if (len > gnl_strlen(s, 0) - (size_t) start)
		aux_len = gnl_strlen(s, 0) - (size_t) start;
	else
		aux_len = len;
	sub = (char *)malloc(aux_len + 1);
	if (!sub)
		return (0);
	i = 0;
	while (s[i + start] && i < (aux_len))
	{
		sub[i] = s[i + start];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*join;
	int		i;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (0);
	len1 = gnl_strlen(s1, 0);
	len2 = gnl_strlen(s2, 0);
	join = (char *)malloc((len1 + len2 + 1));
	if (!join)
		return (0);
	i = -1;
	while (s1[++i])
		join[i] = s1[i];
	i = -1;
	while (s2[++i])
	{
		join[len1] = s2[i];
		len1++;
	}
	join[len1] = '\0';
	free(s1);
	return (join);
}
