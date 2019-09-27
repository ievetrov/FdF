/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonahan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 18:36:56 by lmonahan          #+#    #+#             */
/*   Updated: 2019/01/14 23:04:25 by lmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void		ft_wearefreelst(t_list *con)
{
	while (con->content != NULL)
	{
		free(con->content);
		free(con->next);
		con->next = con;
	}
	free(con);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*tmp;

	new = NULL;
	tmp = NULL;
	if (lst && f)
	{
		tmp = f(lst);
		new = tmp;
		while (lst->next)
		{
			lst = lst->next;
			if (!(tmp->next = f(lst)))
			{
				ft_wearefreelst(tmp);
				return (NULL);
			}
			tmp = tmp->next;
		}
		return (new);
	}
	return (NULL);
}
