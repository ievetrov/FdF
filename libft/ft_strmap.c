/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonahan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 18:49:34 by lmonahan          #+#    #+#             */
/*   Updated: 2019/02/05 20:10:43 by lmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (f)(char))
{
	int		i;
	int		len;
	char	*new;

	i = 0;
	len = 0;
	if (s && f)
	{
		len = ft_strlen(s);
		new = (char*)malloc(sizeof(char) * len + 1);
		if (new == NULL)
			return (NULL);
		while (s[i] != '\0')
		{
			new[i] = f(s[i]);
			i++;
		}
		new[i] = '\0';
		return (new);
	}
	return (NULL);
}
