/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayuso-f <cayuso-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:39:29 by cayuso-f          #+#    #+#             */
/*   Updated: 2024/09/25 15:17:03 by cayuso-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		lst_len;
	t_list	*aux_node;

	lst_len = 0;
	aux_node = lst;
	while (aux_node)
	{
		aux_node = aux_node->next;
		lst_len++;
	}
	return (lst_len);
}
