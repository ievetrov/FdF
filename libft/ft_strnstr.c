/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonahan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 21:23:28 by lmonahan          #+#    #+#             */
/*   Updated: 2019/01/17 19:51:39 by lmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *strb, const char *stra, size_t len)
{
	int		i;
	int		j;

	i = 0;
	if (stra[0] == '\0')
		return ((char *)strb);
	if (i >= (int)len)
		return (NULL);
	while (strb[i] != '\0')
	{
		j = 0;
		while (strb[i + j] == stra[j])
		{
			if (stra[j + 1] == '\0')
			{
				if ((size_t)(i + j) >= len)
					return (NULL);
				return ((char *)&strb[i]);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}
