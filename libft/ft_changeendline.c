/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_changeendline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonahan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 19:49:28 by lmonahan          #+#    #+#             */
/*   Updated: 2019/02/06 21:36:41 by lmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_changeendline(char *tmp)
{
	int	count;

	count = 0;
	while (tmp[count] != '\n' && tmp[count])
		count++;
	if (tmp[count] == '\n')
	{
		tmp[count] = '\0';
		return (count);
	}
	else
		return (-1);
}
