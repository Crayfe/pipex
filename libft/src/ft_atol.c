/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayuso-f <cayuso-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:41:40 by cayuso-f          #+#    #+#             */
/*   Updated: 2024/11/20 13:19:21 by cayuso-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static	int	aux_is_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\f'
		|| c == '\v' || c == '\t' || c == '\r')
		return (1);
	return (0);
}

static	int	aux_clear_spaces(const char *s)
{
	int	i;

	i = 0;
	while (aux_is_space(s[i]))
		++i;
	return (i);
}

long	ft_atol(const char *nptr)
{
	int		i;
	int		sign;
	long	numb;

	sign = 1;
	numb = 0;
	i = aux_clear_spaces(nptr);
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] && ft_isdigit(nptr[i]))
	{
		numb = 10 * numb + (nptr[i] - '0');
		i++;
	}
	return (numb * sign);
}
