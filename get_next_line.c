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

void    *ft_realloc(char *line, size_t len)
{
    char   *arr;

    if ((arr = ft_memalloc(len)) == NULL)
        return (NULL);
    arr = ft_memcpy(arr, line, len);
    free(line);
    if (len < BUFF_SIZE)
    {
        if ((line = ft_memalloc(len)) == NULL)
            return (NULL);
        line = ft_memcpy(line, arr, len);
        return (line);
    }
    else if ((line = ft_memalloc(sizeof(arr) + BUFF_SIZE)) == NULL)
    {
        return (NULL);
        line = ft_memcpy(line, arr, sizeof(arr));
    }
    free(arr);
    return (line);
}

int    check_and_copy(char *buff, char *line)
{
    size_t  i;

    i = 0;
    while (buff[i] != 13 && buff[i] != -1 && i < BUFF_SIZE)
    {
        line[i] = buff[i];
        i++;
    }
    if (i < BUFF_SIZE)
    {
        line[i] = 0;
        line = ft_realloc(line, i);
        return (1);
    }
    









    return (0);

}

int     get_next_line(const int fd, char **line)
{
    static char    buff[BUFF_SIZE];
    
    if (*line != NULL)
        ft_memdel((void **)line);
    if (fd)
    {
        *line = ft_memalloc(BUFF_SIZE);
        read(fd, buff, BUFF_SIZE);
        if (check_and_copy(buff, *line) == 1)

            return (1);

    }
    return (-1);












}















