/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayuso-f <cayuso-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 12:53:25 by cayuso-f          #+#    #+#             */
/*   Updated: 2024/09/25 15:13:17 by cayuso-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*aux_node;

	if (!lst[0])
		lst[0] = new;
	else
	{
		aux_node = lst[0];
		while (aux_node->next)
			aux_node = aux_node->next;
		aux_node->next = new;
	}
}
