/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayuso-f <cayuso-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 19:32:32 by cayuso-f          #+#    #+#             */
/*   Updated: 2024/09/30 11:58:54 by cayuso-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*aux_dest;
	unsigned char	*aux_src;

	aux_dest = (unsigned char *)dest;
	aux_src = (unsigned char *)src;
	if (n == 0 || aux_dest == aux_src)
		return (dest);
	if (aux_dest <= aux_src)
		while (n--)
			*aux_dest++ = *aux_src++;
	else if (aux_dest > aux_src)
	{
		aux_dest = aux_dest + n - 1;
		aux_src = aux_src + n - 1;
		while (n--)
			*aux_dest-- = *aux_src--;
	}
	return (dest);
}
