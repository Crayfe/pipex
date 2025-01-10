/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayuso-f <cayuso-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 10:19:17 by cayuso-f          #+#    #+#             */
/*   Updated: 2024/09/25 15:53:23 by cayuso-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	int		str_len;

	str_len = ft_strlen(s);
	str = (char *)malloc(str_len + 1);
	if (!str)
		return (0);
	ft_strlcpy(str, s, str_len + 1);
	return (str);
}
