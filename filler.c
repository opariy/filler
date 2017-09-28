/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 14:23:21 by opariy            #+#    #+#             */
/*   Updated: 2017/08/02 14:23:23 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_read_piece(char *line, t_request *request)
{
	int		i;
	char	**piece;

	i = 0;
	piece = ft_strsplit(line, ' ');
	request->p_line = ft_atoi(piece[1]);
	request->p_column = ft_atoi(piece[2]);
	request->piece = (char **)malloc(sizeof(char *) * request->p_line + 1);
	while (i < request->p_line)
	{
		get_next_line(0, &line);
		request->piece[i] = ft_strsub(line, 0, (size_t)request->p_column);
		i++;
	}
	request->piece[i] = NULL;
}

void	ft_read_plateau(char *line, t_request *request)
{
	int		i;
	char		**plateau;

	i = 0;
	plateau = ft_strsplit(line, ' ');
	request->line = ft_atoi(plateau[1]);
	request->column = ft_atoi(plateau[2]);
	request->plateau = (char **)malloc(sizeof(char *) * request->line + 1);
	get_next_line(0, &line);
	while (i < request->line)
	{
		get_next_line(0, &line);
		request->plateau[i] = ft_strsub(line, 4, (size_t)request->column);
		i++;
	}
	request->plateau[i] = NULL;
}

void	check_sign(t_request *request, char *line)
{
	if (line[10] == '2')
	{
		request->enemy = 'O';
		request->player = 'X';
	}
	else
	{
		request->enemy = 'X';
		request->player = 'O';
	}
}

void	ft_read(t_request *request)
{
	char	*line;
	int		i;

	i = 0;
	get_next_line(0, &line);
	check_sign(request, line);
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strstr(line, "Plateau"))
			ft_read_plateau(line, request);
		if (ft_strstr(line, "Piece"))
			ft_read_piece(line, request);
		if (request->line != 0 && request->p_line != 0)
		{
			ft_find(request);
			request->line = 0;
			request->p_line = 0;
		}
		i++;
	}
}

void	initialize(t_request *request)
{
	request->line = 0;
	request->column = 0;
	request->player = ' ';
	request->enemy = ' ';
	request->p_column = 0;
	request->p_line = 0;
	request->out_of_bounds = 0;
	request->enemys_c = 0;
	request->my_char = 0;
	request->x = -1;
	request->y = -1;
	request->dist = -1;
	request->dist_min = -1;
	request->x_min = 0;
	request->y_min = 0;
}

int		main(void)
{
	t_request *request;

	request = (t_request *)malloc(sizeof(t_request));
	initialize(request);
	ft_read(request);
	return (0);
}
