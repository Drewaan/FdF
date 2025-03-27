/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 04:05:34 by aamaya-g          #+#    #+#             */
/*   Updated: 2025/01/27 13:21:18 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	main(int argc, char **argv)
{
	char	*file;
	t_map	*map;

	if (argc != 2)
		error_msg(INVALID_ARGS_ERROR);
	file = argv[1];
	check_filename(file);
	map = init_map(file);
	call_mlx(map);
	map_free(map);
	return (SUCCESS);
}
