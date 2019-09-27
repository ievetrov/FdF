/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonahan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 20:33:29 by lmonahan          #+#    #+#             */
/*   Updated: 2019/02/27 23:12:17 by lmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*dest_memcpy;
	const char	*src_memcpy;

	i = 0;
	dest_memcpy = (char *)dest;
	src_memcpy = (const char *)src;
	while (i < n)
	{
		dest_memcpy[i] = src_memcpy[i];
		i++;
	}
	return (dest);
}
