/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdudko <kdudko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 18:30:56 by kdudko            #+#    #+#             */
/*   Updated: 2019/02/08 13:27:37 by kdudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
static void    *ft_realloc(void *ptr, size_t size)
{
    void    *new_ptr;

    if (!ptr)
        return (new_ptr = ft_memalloc(size));
    else if (!size && ptr)
    {
        ft_memdel(&ptr);
        return (new_ptr = ft_memalloc(1));
    }
    else if (!(new_ptr = ft_memalloc(size)))
        return (NULL);
    new_ptr = ft_memmove(new_ptr, ptr, size);
    ft_memdel(&ptr);
    return (new_ptr);
}
*/
int             get_next_line(int fd, char **line)
{
    static size_t   gnl_calls_counter;
    char            buf[2];
    size_t          loop_counter;

    if (fd)
    {
        loop_counter = 1;
        if (gnl_calls_counter == 0)
        {   
            gnl_calls_counter = 1;
            if (*line)
                free(*line);
            if (!(*line = ft_memalloc(BUFF_SIZE + 1)))
                return (-1);
        }
        while (loop_counter <= BUFF_SIZE && read(fd, buf, 1) > 0)
        {
            if (buf[0] == '\n')
            {
                gnl_calls_counter = 0;
                return (1);
            }
            ft_strlcat(*line, buf, BUFF_SIZE * gnl_calls_counter + 1);
            loop_counter++;
        }
        if (loop_counter > BUFF_SIZE)
        {
            gnl_calls_counter++;
            *line = (char *)realloc(*line, loop_counter * gnl_calls_counter);
            get_next_line(fd, &*line);
            return (1);
        }
        if (read(fd, buf, 1) == 0)
        {
            free(*line);
            return (0);
        }
    }
    return (-1);
}
