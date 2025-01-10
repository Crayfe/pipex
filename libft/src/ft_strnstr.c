/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayuso-f <cayuso-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 15:45:59 by cayuso-f          #+#    #+#             */
/*   Updated: 2024/09/25 17:39:33 by cayuso-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	l_size;

	i = 0;
	l_size = ft_strlen(little);
	if (l_size == 0)
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j]
			&& big[i + j] && little[j] && (i + j < len))
			j++;
		if (j == l_size)
			return ((char *)big + i);
		i++;
	}
	return (0);
}
