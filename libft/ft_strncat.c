/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonahan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 16:40:17 by lmonahan          #+#    #+#             */
/*   Updated: 2019/01/07 21:48:36 by lmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *app, size_t n)
{
	size_t		i;
	size_t		j;

	i = ft_strlen(dest);
	j = 0;
	while (app[j] != '\0' && (j < n))
	{
		dest[i + j] = app[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}
