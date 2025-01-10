/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayuso-f <cayuso-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:28:25 by cayuso-f          #+#    #+#             */
/*   Updated: 2024/09/27 11:38:59 by cayuso-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		new_len;
	char	*trim;

	i = 0;
	new_len = ft_strlen(s1);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while ((s1[new_len - 1] && new_len > i)
		&& (ft_strchr(set, s1[new_len - 1])))
		new_len--;
	new_len = new_len - i;
	trim = (char *)malloc(new_len + 1);
	if (!trim)
		return (0);
	ft_strlcpy(trim, (char *)s1 + i, new_len + 1);
	return (trim);
}
