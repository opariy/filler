/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_and_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 16:39:24 by opariy            #+#    #+#             */
/*   Updated: 2017/08/03 16:39:26 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	**create_cropped(t_request *request, int height, int width)
{
	char	**cropped;
	int		i;

	i = 0;
	cropped = (char **)malloc(sizeof(char *) * request->p_line + 1);
	if (((width + request->p_column - 1) < request->column) &&
			((height + request->p_line - 1) < request->line))
	{
		while (i < request->p_line)
		{
			cropped[i] = ft_strsub((char const*)request->plateau[height],
	(unsigned int)width,
	(size_t)request->p_column);
			height++;
			i++;
		}
		cropped[i] = NULL;
	}
	else
		request->out_of_bounds = 1;
	return (cropped);
}

float	get_distance(t_request *request, int height, int width)
{
	int		x_d;
	int		y_d;
	float	dist;
	float	dist_min;

	dist_min = -1;
	while ((request->plateau)[height])
	{
		width = 0;
		while ((request->plateau)[height][width])
		{
			if ((request->plateau)[height][width] == request->enemy)
			{
				if (height > request->y)
					y_d = height - request->y;
				else
					y_d = request->y - height;
				if (width > request->x)
					x_d = width - request->x;
				else
					x_d = request->x - width;
				dist = y_d + x_d;
				if (dist_min == -1)
					dist_min = dist;
				else if (dist < dist_min)
					dist_min = dist;
			}
			width++;
		}
		height++;
	}
	return (dist_min);
}

void	check_placed(t_request *request, int height, int width)
{
	char	**cropped;
	int		h;
	int		w;

	w = 0;
	h = 0;
	request->out_of_bounds = 0;
	request->my_char = 0;
	request->enemys_c = 0;
	request->y = height;
	request->x = width;
	request->dist = -1;
	cropped = create_cropped(request, height, width);
	if (request->out_of_bounds == 0)
	{
		height = 0;
		while (height < request->p_line)
		{
			width = 0;
			while (width < request->p_column)
			{
				if (((request->piece)[height][width] == '*') &&
						cropped[height][width] == request->player)
					request->my_char++;
				if (cropped[height][width] == request->enemy)
					request->enemys_c++;
				width++;
			}
			height++;
		}
	}
	if ((request->my_char == 1) && (request->enemys_c == 0) &&
			(request->out_of_bounds == 0))
	{
		request->dist = get_distance(request, h, w);
		if (request->dist_min == -1)
		{
			request->x_min = request->x;
			request->y_min = request->y;
			request->dist_min = request->dist;
		}
		if (request->dist <= request->dist_min && request->dist != -1)
		{
			request->x_min = request->x;
			request->y_min = request->y;
			request->dist_min = request->dist;
		}
	}
}

void	ft_find(t_request *request)
{
	int		height;
	int		width;

	height = 0;
	request->x_min = 0;
	request->y_min = 0;
	request->dist_min = -1;
	while (height < request->line)
	{
		width = 0;
		while (width < request->column)
		{
			check_placed(request, height, width);
			width++;
		}
		height++;
	}
	ft_putnbr(request->y_min);
	ft_putchar(' ');
	ft_putnbr(request->x_min);
	ft_putchar('\n');
}
