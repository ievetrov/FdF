/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonahan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 21:10:12 by lmonahan          #+#    #+#             */
/*   Updated: 2018/12/11 21:21:50 by lmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*copy;
	unsigned char	*temp;

	copy = (unsigned char*)dest;
	temp = (unsigned char*)src;
	if (dest == src)
		return (dest);
	while (n--)
	{
		*copy++ = *temp;
		if (*temp++ == (unsigned char)c)
			return (copy);
	}
	return (NULL);
}
