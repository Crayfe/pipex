/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayuso-f <cayuso-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 11:38:14 by cayuso-f          #+#    #+#             */
/*   Updated: 2024/10/11 12:56:28 by cayuso-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_str(char *s)
{
	int	i;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (s[i])
	{
		write(1, s + i, 1);
		i++;
	}
	return (i);
}

int	ft_print_nbr(int n)
{
	unsigned int	aux_int;
	int				chars;

	aux_int = 0;
	chars = 0;
	if (n < 0)
	{
		ft_print_char('-');
		aux_int = -1 * n;
		++chars;
	}
	else
		aux_int = n;
	if (aux_int > 9)
		chars += ft_print_nbr(aux_int / 10);
	ft_print_char(aux_int % 10 + '0');
	++chars;
	return (chars);
}

int	ft_print_nbr_base(unsigned long n, char *base)
{
	int		chars;
	int		len;

	chars = 0;
	len = 0;
	while (base[len])
		++len;
	if (n >= (unsigned long)len)
		chars += ft_print_nbr_base(n / len, base);
	ft_print_char(base[n % len]);
	++chars;
	return (chars);
}

int	ft_print_ptr(unsigned long ptr)
{
	int	n;

	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	n = 0;
	n += ft_print_str("0x");
	n += ft_print_nbr_base(ptr, "0123456789abcdef");
	return (n);
}
