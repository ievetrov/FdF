/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonahan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 20:59:34 by lmonahan          #+#    #+#             */
/*   Updated: 2019/02/05 20:12:39 by lmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*new;

	i = 0;
	new = NULL;
	if (s && (ft_strlen(s) >= (size_t)start))
	{
		new = (char*)malloc(sizeof(char) * (len + 1));
		if (new == NULL)
			return (NULL);
		while (i < len && s[start] != '\0')
		{
			new[i] = s[start];
			start++;
			i++;
		}
		new[i] = '\0';
		return (new);
	}
	return (NULL);
}
