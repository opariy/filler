/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 15:23:47 by opariy            #+#    #+#             */
/*   Updated: 2017/06/28 16:06:12 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include "libft/libft.h"
# include <unistd.h>
# define BUFF_SIZE 32
# define TAIL found_el->content

int get_next_line(const int fd, char **line);

#endif
