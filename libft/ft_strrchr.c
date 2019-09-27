/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonahan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 20:46:05 by lmonahan          #+#    #+#             */
/*   Updated: 2019/01/11 19:03:26 by lmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	char	*src;
	int		i;
	int		len;

	src = (char*)str;
	i = 0;
	len = ft_strlen(src);
	while (len >= 0)
	{
		if (src[len] == (char)ch)
			return (src + len);
		len--;
	}
	return (NULL);
}
