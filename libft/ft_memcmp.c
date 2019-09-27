/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonahan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 23:14:32 by lmonahan          #+#    #+#             */
/*   Updated: 2019/01/07 20:35:17 by lmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *arr1, const void *arr2, size_t n)
{
	unsigned char	*cp_arr1;
	unsigned char	*cp_arr2;
	size_t			i;

	cp_arr1 = (unsigned char *)arr1;
	cp_arr2 = (unsigned char *)arr2;
	i = 0;
	if (cp_arr1 == cp_arr2 || n == 0)
		return (0);
	while (i < n - 1 && cp_arr1[i] == cp_arr2[i])
		i++;
	return (cp_arr1[i] - cp_arr2[i]);
}
