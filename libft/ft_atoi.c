/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonahan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 21:57:00 by lmonahan          #+#    #+#             */
/*   Updated: 2019/02/19 20:33:34 by lmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_bl(const char *str, int *i)
{
	while (str[*i] == '\n' || str[*i] == ' ' || str[*i] == '\t' ||
		str[*i] == '\v' || str[*i] == '\r' || str[*i] == '\f')
		*i = *i + 1;
}

int			ft_atoi(const char *str)
{
	int						i;
	unsigned long long int	res;
	unsigned long long int	subzero;

	i = 0;
	res = 0;
	subzero = 1;
	ft_bl(str, &i);
	if (str[i] == '-')
		subzero = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (long long int)(str[i] - '0');
		i++;
	}
	if (i > 19 || res >= 9223372036854775807)
		return (subzero == 1 ? -1 : 0);
	return (res * subzero);
}
