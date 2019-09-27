/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maxofarray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonahan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 20:48:17 by lmonahan          #+#    #+#             */
/*   Updated: 2019/02/27 22:51:32 by lmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_maxofarray(int *arr, int size)
{
	int i;
	int max;
	int val;

	i = 0;
	max = 0;
	if (arr || size)
	{
		max = arr[0];
		while (i < size)
		{
			val = arr[i];
			if (val > max)
				max = val;
			i++;
		}
	}
	return (max);
}
