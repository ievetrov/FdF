/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonahan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 16:27:38 by lmonahan          #+#    #+#             */
/*   Updated: 2019/02/27 21:57:19 by lmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char		*ft_myword(char const *s, char c, size_t *i, char ***res)
{
	size_t	k;
	char	*split;

	k = 0;
	if (ft_strlen(s) == 0)
		return (NULL);
	if (!s || !(split = (char*)malloc(sizeof(char) *
				ft_len_word(&s[*i], c) + 1)))
	{
		ft_wearefree(res);
		return (NULL);
	}
	while (s[*i] != c && s[*i])
	{
		split[k] = s[*i];
		k++;
		*i = *i + 1;
	}
	split[k] = '\0';
	while (s[*i] == c && s[*i])
		*i = *i + 1;
	return (split);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**res;
	size_t	i;
	size_t	j;
	size_t	total;

	i = 0;
	if (s && c)
	{
		total = ft_countallsplit(s, c);
		if (!(res = (char**)malloc(sizeof(char*) * total + 1)))
			return (NULL);
		j = 0;
		while (s[i] == c && s[i])
			i++;
		while (j <= total && s[i])
		{
			res[j] = ft_myword(s, c, &i, &res);
			j++;
		}
		res[j] = NULL;
		return (res);
	}
	return (NULL);
}
