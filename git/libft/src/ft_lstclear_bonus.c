/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armgonza <armgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 19:52:08 by armgonza          #+#    #+#             */
/*   Updated: 2023/10/31 21:22:44 by armgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*next_elem;

	if (!lst || !del)
		return ;
	tmp = *lst;
	while (tmp)
	{
		next_elem = tmp->next;
		del(tmp->content);
		free(tmp);
		tmp = next_elem;
	}
	*lst = NULL;
}
