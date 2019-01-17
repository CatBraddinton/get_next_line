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


{
    t_list *head;
    t_list *link;

    head = NULL;
    *link = (t_list *)malloc(sizeof(t_list));
}

int     get_next_line(const int fd, char **line)
{

    if (fd)
    {
        while (read(fd, link, BUFF_SIZE) != 0)
        {
            link = link->next;
        }

    }
    return(-1);
}
