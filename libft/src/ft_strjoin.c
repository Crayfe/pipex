/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayuso-f <cayuso-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:27:23 by cayuso-f          #+#    #+#             */
/*   Updated: 2024/09/26 14:10:21 by cayuso-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		len1;
	int		len2;

	if (!s1 || !s2)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	join = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!join)
		return (0);
	ft_strlcpy(join, s1, len1 + 1);
	ft_strlcat(join, s2, len1 + len2 + 1);
	return (join);
}
