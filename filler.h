/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 15:19:15 by opariy            #+#    #+#             */
/*   Updated: 2017/08/01 15:19:17 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <fcntl.h>
# include "libft/libft.h"
# include <unistd.h>
# define BUFF_SIZE 32
# define TAIL found_el->content

typedef struct	s_request
{
	int			line;
	int			column;
	char		player;
	char		enemy;
	int			p_line;
	int			p_column;
	char		**plateau;
	char		**piece;
	float		dist_min;
	int			out_of_bounds;
	int			enemys_c;
	int			my_char;
	int			x;
	int			y;
	int			x_min;
	int			y_min;
	float		dist;
}				t_request;

int				get_next_line(const int fd, char **line);
void			ft_find(t_request *request);

#endif
