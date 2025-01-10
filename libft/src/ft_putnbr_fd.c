/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayuso-f <cayuso-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:40:14 by cayuso-f          #+#    #+#             */
/*   Updated: 2024/09/26 13:04:00 by cayuso-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	aux_int;

	aux_int = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		aux_int = -1 * n;
	}
	else
		aux_int = n;
	if (aux_int > 9)
		ft_putnbr_fd(aux_int / 10, fd);
	ft_putchar_fd(aux_int % 10 + '0', fd);
}
