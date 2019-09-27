/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonahan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 21:57:00 by lmonahan          #+#    #+#             */
/*   Updated: 2019/01/14 17:53:12 by lmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	int		ft_getlen(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char	*res;
	int		size;
	int		subzero;

	subzero = 0;
	size = ft_getlen(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		n = n * (-1);
		subzero = -1;
	}
	if (!(res = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	res[size] = '\0';
	while (size--)
	{
		res[size] = (n % 10) + '0';
		n = n / 10;
	}
	if (subzero == -1)
		res[0] = '-';
	return (res);
}
