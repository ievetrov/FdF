/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonahan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 21:58:23 by lmonahan          #+#    #+#             */
/*   Updated: 2019/02/27 23:11:58 by lmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;

	i = 0;
	if (src < dest)
	{
		while (n > 0)
		{
			n--;
			((char*)dest)[n] = ((const char*)src)[n];
		}
	}
	else
	{
		while (i < n)
		{
			((char*)dest)[i] = ((const char*)src)[i];
			i++;
		}
	}
	return (dest);
}
