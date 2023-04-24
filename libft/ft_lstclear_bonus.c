/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:41:24 by yzaytoun          #+#    #+#             */
/*   Updated: 2023/03/31 20:05:10 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*point;

	if (!lst || !del || (*lst) == NULL)
		return ;
	point = (*lst);
	while (point != NULL)
	{
		point = (*lst);
		(*lst) = point->next;
		(del)(point->content);
		free(point);
		point = (*lst);
	}
	(*lst) = NULL;
}
