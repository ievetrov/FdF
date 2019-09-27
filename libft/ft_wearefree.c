/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wearefree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonahan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 23:27:34 by lmonahan          #+#    #+#             */
/*   Updated: 2019/01/18 23:35:49 by lmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_wearefree(char ***res)
{
	size_t len;

	len = 0;
	while (res != NULL)
	{
		free((res)[len]);
		len++;
	}
	free(*res);
}
