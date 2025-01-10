/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayuso-f <cayuso-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:52:51 by cayuso-f          #+#    #+#             */
/*   Updated: 2024/09/27 11:39:57 by cayuso-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static	int	aux_getlen(long n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		n = -n;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*itoa;
	int		len;
	long	aux_n;

	aux_n = n;
	len = aux_getlen(aux_n);
	itoa = (char *)malloc(len + 1);
	if (!itoa)
		return (0);
	itoa[len] = '\0';
	if (n == 0)
		itoa[0] = '0';
	if (n < 0)
	{
		itoa[0] = '-';
		aux_n = -aux_n;
	}
	while (aux_n > 0)
	{
		itoa[--len] = '0' + (aux_n % 10);
		aux_n = aux_n / 10;
	}
	return (itoa);
}
