/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonahan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 14:41:55 by lmonahan          #+#    #+#             */
/*   Updated: 2019/02/05 20:13:37 by lmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	size_t	st;
	size_t	end;
	size_t	n;
	char	*res;

	st = 0;
	if (s)
	{
		end = ft_strlen(s) - 1;
		while (s[st] == ' ' || s[st] == '\n' || s[st] == '\t')
			st++;
		while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
			end--;
		n = end - st + 1;
		if (st == ft_strlen(s))
			n = 1;
		if (!(res = (char*)malloc(sizeof(char) * n + 1)))
			return (NULL);
		ft_strncpy(res, &s[st], n);
		res[n] = '\0';
		return (res);
	}
	return (NULL);
}
