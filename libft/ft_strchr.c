/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonahan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 19:41:50 by lmonahan          #+#    #+#             */
/*   Updated: 2019/01/11 18:43:36 by lmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*src;
	int		i;

	src = (char*)s;
	i = 0;
	while (src[i] != (char)c)
	{
		if (src[i] == '\0')
			return (NULL);
		i++;
	}
	return (src + i);
}
