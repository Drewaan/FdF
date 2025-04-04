/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 19:38:05 by aamaya-g          #+#    #+#             */
/*   Updated: 2024/05/21 14:54:19 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*clean;

	if (!*lst)
		return ;
	while (*lst)
	{
		clean = (*lst)-> next;
		ft_lstdelone(*lst, del);
		*lst = clean;
	}
	free(*lst);
	*lst = NULL;
}
