/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 15:15:47 by opariy            #+#    #+#             */
/*   Updated: 2017/06/28 15:18:24 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		f(char *tail, char **line, int n, t_list *found_el)
{
	if (ft_strchr(tail, '\n'))
	{
		*line = ft_strsub(tail, 0, ft_strchr(tail, '\n') - tail);
		found_el->content = ft_strdup(ft_strchr(tail, '\n') + 1);
		return (1);
	}
	if (!n && !tail[0])
	{
		*line = ft_strnew(0);
		return (0);
	}
	if (n == 0)
	{
		*line = ft_strdup(tail);
		tail[0] = 0;
		found_el->content = tail;
		return (1);
	}
	return (-1);
}

int		read_new_line(t_list *found_el, char **line)
{
	char	buf[BUFF_SIZE + 1];
	int		n;
	int		i[2];

	buf[BUFF_SIZE] = '\0';
	if (!TAIL)
		TAIL = ft_strnew(0);
	if (ft_strchr(TAIL, '\n'))
	{
		*line = ft_strsub(TAIL, 0, ft_strchr(TAIL, '\n') - (char*)TAIL);
		TAIL = ft_strdup(ft_strchr(TAIL, '\n') + 1);
		return (1);
	}
	i[0] = -1;
	while ((n = read((int)(found_el->content_size), buf, BUFF_SIZE)) >= 0)
	{
		if (n < BUFF_SIZE)
			while (++i[0] < BUFF_SIZE - n)
				buf[n + i[0]] = '\0';
		i[0] = -1;
		TAIL = ft_strjoin(TAIL, buf);
		if ((i[1] = f(TAIL, line, n, found_el)) >= 0)
			return (i[1]);
	}
	return (-1);
}

t_list	*push_back(t_list *head, size_t fd)
{
	while (head->next)
	{
		head = head->next;
	}
	head->next = (t_list *)malloc(sizeof(t_list));
	head = head->next;
	head->content = ft_strnew(0);
	head->content_size = fd;
	head->next = NULL;
	return (head);
}

t_list	*find_by_fd(t_list *lst, size_t fd)
{
	while (lst)
	{
		if (lst->content_size == fd)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*lst;
	t_list			*found_el;

	if (!lst)
	{
		lst = (t_list *)malloc(sizeof(t_list));
		lst->content_size = 0;
		lst->content = ft_strnew(0);
		lst->next = NULL;
	}
	found_el = find_by_fd(lst, (size_t)fd);
	if (found_el)
		return (read_new_line(found_el, line));
	else
	{
		found_el = push_back(lst, (size_t)fd);
		return (read_new_line(found_el, line));
	}
}
