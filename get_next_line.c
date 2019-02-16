/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdudko <kdudko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 16:10:01 by kdudko            #+#    #+#             */
/*   Updated: 2019/02/16 16:13:12 by kdudko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	create_node(gnl_list **head)
{
	gnl_list *node;
	node = (gnl_list *)malloc(sizeof(gnl_list));
	node->next = *head;
	*head = node;
}

void	del_one_node(gnl_list **head)
{
	gnl_list	*temp;

	if (*head)
	{
		temp = (*head)->next;
		free((*head)->new_line);
		free(*head);
		(*head) = temp;
	}
}

void	buffer_to_list(gnl_list **head, char *str, const int fd, size_t read_ret)
{
	char 	*p;
	int 	i = 0;

	p = str;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			str[i] = '\0';
			create_node(head);
			(*head)->new_line = ft_strdup(p);
			(*head)->curr_fd = fd;
			p = &str[i + 1];
		}
		i++;
	}
	if (*p != '\0')
		{
			create_node(head);
			(*head)->new_line = ft_strdup(p);
			free(str);
			str = ft_strnew(BUFF_SIZE + 1);
			read_ret = read(fd, str, BUFF_SIZE);
			ft_strlcat((*head)->new_line, str, ft_strlen((*head)->new_line) + ft_strlen(str) + 1);
			free(str);
			str = ft_strndup((*head)->new_line, ft_strlen((*head)->new_line));
			del_one_node(head);
			p = str;
		}
	if (read_ret == 0)
	{
		if (*p)
		{
			create_node(head);
			(*head)->new_line = (char *)malloc(ft_strlen(p) + 1);
			ft_strlcpy((*head)->new_line, p, ft_strlen(p) + 1);
			(*head)->curr_fd = fd;
			p = NULL;
		}
	}
}

void	reverse_list(gnl_list **head)
{
	gnl_list	*current;
	gnl_list	*prev;
	gnl_list	*next;

	current = *head;
	prev = NULL;
	next = NULL;
	while (current)
	{
		next  = current->next;
		current->next = prev;
		prev = current; 
        current = next;
	}
	*head = prev;
}

int		get_next_line(const int fd, char **line)
{
	static gnl_list	*head;
	char			*buffer;
	size_t			read_ret;

	if (!fd)
		return (-1);
	if (*line)
		ft_memdel((void **)line);
	if (!head)
	{
		buffer = (char *)malloc((BUFF_SIZE + 1) * sizeof(char));
		read_ret = read(fd, buffer, BUFF_SIZE);
		buffer[read_ret] = '\0';
		buffer_to_list(&head, buffer, fd, read_ret);
		reverse_list(&head);
	}
	else if (head)
	{
		*line = ft_strdup(head->new_line);
		del_one_node(&head);
	}
	return (1);
}