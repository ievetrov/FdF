/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minofarray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonahan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 20:48:17 by lmonahan          #+#    #+#             */
/*   Updated: 2019/02/27 22:51:45 by lmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_minofarray(int *arr, int size)
{
	int i;
	int min;
	int val;

	i = 0;
	min = 0;
	if (arr || size)
	{
		min = arr[0];
		while (i < size)
		{
			val = arr[i];
			if (val < min)
				min = val;
			i++;
		}
	}
	return (min);
}
