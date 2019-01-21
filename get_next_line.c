/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdudko <kdudko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 18:30:56 by kdudko            #+#    #+#             */
/*   Updated: 2019/01/17 18:31:03 by kdudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int     get_next_line(const int fd, char **line)
{
    static char buff[BUFF_SIZE];
    t_list      *head;
    t_list      *link;

    if (fd)
    {   
        read(fd, buff, BUFF_SIZE);
        link = ft_lstnew(buff, BUFF_SIZE);
        head = link;
        ft_bzero(ft_memchr((const void *)link->content, 13, BUFF_SIZE), BUFF_SIZE - sizeof(link->content));
        *line = ft_strnew(sizeof(link->content));
        *line = ft_memcpy(line, link->content, sizeof(link->content));
        link = ft_lstnew(buff + sizeof(link->content), BUFF_SIZE);
        ft_bzero(buff, BUFF_SIZE);
        return (1);
        
    }
    return (-1);
}
