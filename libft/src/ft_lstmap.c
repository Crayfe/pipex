/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayuso-f <cayuso-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:26:49 by cayuso-f          #+#    #+#             */
/*   Updated: 2024/09/30 11:48:28 by cayuso-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*aux_node;
	void	*aux_content;

	new_list = 0;
	while (lst && (f && del))
	{
		aux_content = f(lst-> content);
		if (!aux_content)
		{
			ft_lstclear(&new_list, del);
			return (0);
		}
		aux_node = ft_lstnew(aux_content);
		if (!aux_node)
		{
			del(aux_content);
			ft_lstclear(&new_list, del);
			return (0);
		}
		ft_lstadd_back(&new_list, aux_node);
		lst = lst-> next;
	}
	return (new_list);
}
