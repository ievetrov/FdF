/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonahan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 19:29:52 by lmonahan          #+#    #+#             */
/*   Updated: 2019/01/14 12:26:28 by lmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest_memset, int c, size_t n)
{
	size_t	i;
	char	*copy_memset;

	i = 0;
	copy_memset = (char *)dest_memset;
	while (i < n)
	{
		copy_memset[i] = c;
		i++;
	}
	return (dest_memset);
}
