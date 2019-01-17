/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdudko <kdudko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 10:24:46 by kdudko            #+#    #+#             */
/*   Updated: 2019/01/05 10:25:35 by kdudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int			get_next_line(const int fd, char **line)
{
	static char	buff[BUFF_SIZE + 1];
	size_t 		i;

	i = 0;
	while (i < BUFF_SIZE)
	{
		read(fd, &buff[i], 1);
		if ((buff[i] == '\n') || (buff[i] == EOF))
		{
			*line = ft_strsub(buff, 0, i - 1);
			printf("%s\n", *line);
			return (1);
		}
		i++;
	}
	return (0);
}
