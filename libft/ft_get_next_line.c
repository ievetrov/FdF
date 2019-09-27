/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmonahan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 19:36:40 by lmonahan          #+#    #+#             */
/*   Updated: 2019/04/30 20:28:23 by lmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_changeendlin(char *tmp)
{
	int count;

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

static char		*ft_join(char *buff, char *src, size_t buffsize)
{
	size_t	lenbuff;
	size_t	lensrc;
	char	*tmp;

	lenbuff = 0;
	lensrc = 0;
	if (buff)
		lenbuff = ft_strlen(buff);
	if (src)
		lensrc = ft_strlen(src);
	if (!(tmp = (char *)malloc(sizeof(*tmp) * (lenbuff + lensrc + 1))))
		return (NULL);
	ft_memcpy(tmp, buff, lenbuff);
	ft_memcpy(tmp + lenbuff, src, lensrc);
	tmp[lenbuff + lensrc] = '\0';
	free(buff);
	ft_bzero(src, buffsize + 1);
	return (tmp);
}

static int		ft_isendblok(char **buff, char **tab, char **line,
							size_t buffsize)
{
	char	*ptr;
	int		endofline;

	*buff = ft_join(*buff, *tab, buffsize);
	endofline = ft_changeendlin(*buff);
	if (endofline > -1)
	{
		*line = ft_strdup(*buff);
		ptr = *buff;
		*buff = ft_strdup(*buff + endofline + 1);
		free(ptr);
		return (1);
	}
	return (0);
}

static int		ft_readblok(int const fd, char **buff, char *tmp, char **line)
{
	int result;

	result = 0;
	while ((read(fd, tmp, BUFF_SIZE)) > 0)
	{
		result = ft_isendblok(&buff[fd], &tmp, line, BUFF_SIZE);
		free(tmp);
		if (result == 1)
			return (1);
		tmp = ft_strnew(BUFF_SIZE);
	}
	if ((result = ft_isendblok(&buff[fd], &tmp, line, BUFF_SIZE)))
		return (1);
	else if (ft_strlen(buff[fd]) > 0)
	{
		*line = ft_strdup(buff[fd]);
		ft_strdel(&buff[fd]);
		return (1);
	}
	free(tmp);
	return (result);
}

int				ft_get_next_line(int const fd, char **line)
{
	static char	*buff[11000];
	char		*tmp;
	int			ret;

	tmp = ft_strnew(BUFF_SIZE);
	if (!line || BUFF_SIZE <= 0 || fd < 0 || (read(fd, tmp, 0)) < 0)
		return (-1);
	ret = ft_readblok(fd, &buff[fd], tmp, line);
	return (ret);
}
