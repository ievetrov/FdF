/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonahan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 20:36:39 by lmonahan          #+#    #+#             */
/*   Updated: 2019/01/11 22:38:36 by lmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int		res;
	size_t	i;

	res = 1;
	i = 0;
	if (!n)
		return (1);
	if (s1 && s2 && n)
	{
		while (n > 0)
		{
			if (s1[i] != s2[i])
				res = 0;
			i++;
			n--;
		}
	}
	return (res);
}
