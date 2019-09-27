/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonahan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 15:31:46 by lmonahan          #+#    #+#             */
/*   Updated: 2019/01/14 15:00:17 by lmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *destination, const char *source, size_t n)
{
	size_t		i;
	char		*dest;
	const char	*src;

	i = 0;
	src = (const char *)source;
	dest = (char *)destination;
	while (i < n)
	{
		if (src[i] != '\0')
			dest[i] = src[i];
		else
			while (i < n)
			{
				dest[i] = '\0';
				i++;
			}
		i++;
	}
	return (dest);
}
