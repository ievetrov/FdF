/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonahan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 21:46:19 by lmonahan          #+#    #+#             */
/*   Updated: 2019/02/05 20:13:01 by lmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*new;
	size_t	i;

	i = 0;
	len = 0;
	new = NULL;
	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		new = (char*)malloc(sizeof(char) * (len + 1));
		if (new == NULL)
			return (NULL);
		ft_strcpy(new, s1);
		ft_strcat(new, s2);
		new[len + 1] = '\0';
		return (new);
	}
	return (NULL);
}
