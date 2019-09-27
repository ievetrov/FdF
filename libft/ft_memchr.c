/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonahan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 22:02:57 by lmonahan          #+#    #+#             */
/*   Updated: 2019/01/07 20:33:29 by lmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	size_t			i;
	unsigned char	*copy_arr;

	i = 0;
	copy_arr = (unsigned char *)arr;
	while (i < n)
	{
		if (copy_arr[i] == (unsigned char)c)
			return (&copy_arr[i]);
		i++;
	}
	return (NULL);
}
