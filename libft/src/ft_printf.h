/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayuso-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:46:37 by cayuso-f          #+#    #+#             */
/*   Updated: 2024/10/02 15:50:40 by cayuso-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(char const *s, ...);
int	ft_print_char(char c);
int	ft_print_str(char *s);
int	ft_print_nbr(int nb);
int	ft_print_nbr_base(unsigned long nb, char *base);
int	ft_print_ptr(unsigned long ptr);

#endif
