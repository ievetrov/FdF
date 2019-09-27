/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonahan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 17:58:06 by lmonahan          #+#    #+#             */
/*   Updated: 2019/02/19 20:18:01 by lmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*array;

	if ((size + 1) == 0)
		return (NULL);
	if (!(array = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_memset(array, (int)'\0', size + 1);
	return (array);
}
