/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdudko <kdudko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 10:25:44 by kdudko            #+#    #+#             */
/*   Updated: 2019/02/14 13:46:30 by kdudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/libft.h"
# include <stdio.h>

# define BUFF_SIZE	144

typedef	struct 			s_list_gnl
{
	char				*new_line;
	int					curr_fd;
	struct s_list_gnl 	*next;
}						gnl_list;

int	get_next_line(const int fd, char **line);

#endif
