/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonahan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 14:16:25 by lmonahan          #+#    #+#             */
/*   Updated: 2019/01/07 21:42:38 by lmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *str)
{
	char	*ret;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	ret = (char *)malloc((len + 1) * sizeof(*str));
	if (ret == 0)
		return (NULL);
	while (i < len)
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
