/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonahan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 21:23:28 by lmonahan          #+#    #+#             */
/*   Updated: 2019/02/05 20:03:23 by lmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *strb, const char *stra)
{
	int	i;
	int	j;

	i = 0;
	if (stra[0] == '\0')
		return ((char *)strb);
	while (strb[i] != '\0')
	{
		j = 0;
		while (strb[i + j] == stra[j])
		{
			if (stra[j + 1] == '\0')
				return ((char *)&strb[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
