/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayuso-f <cayuso-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:29:43 by cayuso-f          #+#    #+#             */
/*   Updated: 2024/09/26 13:53:08 by cayuso-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	k;

	i = ft_strlen(dst);
	k = ft_strlen(src);
	if ((!dst || !src) && size == 0)
		return (0);
	if (size < i)
		return (size + k);
	ft_strlcpy(dst + i, src, size - i);
	return (i + k);
}
