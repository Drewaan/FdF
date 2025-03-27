/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 04:24:37 by aamaya-g          #+#    #+#             */
/*   Updated: 2025/01/28 14:08:43 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	error_msg(int exit_msg)
{
	ft_printf("%s", COLOR_ERROR_MSG);
	if (exit_msg == INVALID_ARGS_ERROR)
		ft_printf("unvalid argc, use: ./fdf map.fdf\n");
	else if (exit_msg == FILE_OPEN_ERROR)
		ft_printf("Failed to open file\n");
	else if (exit_msg == MEM_ALLOC_ERROR)
		ft_printf("Failed memory allocation dude\n");
	else if (exit_msg == MAP_EMPTY_ERROR)
		ft_printf("Map is empty...\n");
	else if (exit_msg == LIBFT_ERROR)
		ft_printf("Libft error\n ");
	else if (exit_msg == MLX_ERROR)
		ft_printf("MLX error\n");
	else if (exit_msg == SUCCESS)
		ft_printf("The program ran successfully :D\n");
	else if (exit_msg == INVALID_FILENAME_ERROR)
		ft_printf("Filename error, please check it bro\n");
	else
		ft_printf("invalid map\n");
	ft_printf("%s", RESET_ERROR_MSG);
	exit(exit_msg);
}

void	check_filename(const char *filename)
{
	const char	*extension;
	size_t		len;
	size_t		len_extension;

	extension = ".fdf";
	len = ft_strlen(filename);
	len_extension = ft_strlen(extension);
	if (len < len_extension || ft_strcmp(filename + len - len_extension,
			extension) != 0)
		error_msg(INVALID_FILENAME_ERROR);
}
