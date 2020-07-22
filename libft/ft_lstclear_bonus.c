/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 08:59:05 by mel-kada          #+#    #+#             */
/*   Updated: 2020/02/24 08:59:12 by mel-kada         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *elem;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		del((*lst)->content);
		elem = *lst;
		*lst = elem->next;
		free(elem);
	}
	*lst = NULL;
}
