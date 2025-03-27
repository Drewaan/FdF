/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:17:41 by aamaya-g          #+#    #+#             */
/*   Updated: 2025/03/20 13:09:40 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	map_size(int fd, t_map *map)
{
	char	*line;
	char	**split;

	line = get_next_line(fd);
	split = ft_split(line, ' ');
	map -> width = find_width(split);
	while (line)
	{
		map -> height++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}

void	map_mem(int fd, t_map *map)
{
	int		i;
	int		j;
	char	*line;
	char	**split;

	i = -1;
	map_alloc(map);
	while (++i < map -> height)
	{
		line = get_next_line(fd);
		split = ft_split(line, ' ');
		if (!split[0] || !split[1])
		{
			map_free(map);
			error_msg(CREATION_ERROR);
		}
		j = -1;
		while (split[++j])
		{
			map -> z_2d[i][j] = z_value(ft_atoi(split[j]), map);
			map -> colors[i][j] = convert_hex_color(split[j], map);
		}
		free(line);
		ft_free(split);
	}
}

t_map	*init_map(char *filename)
{
	int		fd;
	t_map	*map;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_msg(FILE_OPEN_ERROR);
	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		error_msg(MEM_ALLOC_ERROR);
	map_size(fd, map);
	fd = open (filename, O_RDONLY);
	if (fd < 0)
		error_msg(FILE_OPEN_ERROR);
	map_mem(fd, map);
	close(fd);
	return (map);
}
