/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayuso-f <cayuso-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:08:43 by cayuso-f          #+#    #+#             */
/*   Updated: 2024/09/25 16:20:33 by cayuso-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux_node;

	while (lst[0])
	{
		aux_node = lst[0]->next;
		ft_lstdelone(lst[0], del);
		lst[0] = aux_node;
	}
	lst[0] = 0;
}
