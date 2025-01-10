/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayuso-f <cayuso-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:25:29 by cayuso-f          #+#    #+#             */
/*   Updated: 2024/09/30 11:34:26 by cayuso-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	aux_len;

	if (!s)
		return (0);
	if ((size_t) start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - (size_t) start)
		aux_len = ft_strlen(s) - (size_t) start;
	else
		aux_len = len;
	sub = (char *)malloc(aux_len + 1);
	if (!sub)
		return (0);
	ft_strlcpy(sub, s + start, aux_len + 1);
	return (sub);
}
