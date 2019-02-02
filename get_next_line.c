/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdudko <kdudko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 18:30:56 by kdudko            #+#    #	#             */
/*   Updated: 2019/01/29 13:30:29 by kdudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int    buff_proccessing(char *buff, char *line)
{
    char *str;
    int i;

    str = (char *)malloc((BUFF_SIZE + 1) * sizeof(char));
    i = 0;
    while (i < BUFF_SIZE)
    {
        str[i] = buff[i];
        if (str[i] == 13)
        {
            str[i] = '\0';
            line = (char *) malloc(ft_strlen(str) * sizeof(char));
            line = ft_strcpy(line, str);
            i = 0;
        }
        i++;
    }
    if (i != BUFF_SIZE)
        return (1);
}

int     get_next_line(const int fd, char **line)
{
	static char buff[BUFF_SIZE];
	
	if (fd)
    {
	    read(fd, buff, BUFF_SIZE);
	    if ((buff_proccessing(buff, &line)) == 1)
	        return (1);

    }
	return (-1);
}
