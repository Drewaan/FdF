/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 03:10:30 by aamaya-g          #+#    #+#             */
/*   Updated: 2025/01/28 13:57:13 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	handle_key(int key, t_data *fdf)
{
	if (key == ESC_KEY)
		close_window(fdf);
	if (key == R_KEY)
		reset(fdf);
	if (key == TAB_KEY)
		fdf -> isometric = fdf -> isometric ^ 1;
	if (key == PLUS_KEY || key == MINUS_KEY)
		zoom(key, fdf);
	if (key == W_KEY || key == A_KEY || key == S_KEY || key == D_KEY)
		translation(key, fdf);
	if (key == KEY_1 || key == KEY_2 || key == KEY_3
		|| key == KEY_4 || key == KEY_5 || key == KEY_6)
		rotation(key, fdf);
	if (key == UP_KEY || key == DOWN_KEY)
		altitude(key, fdf);
	if (key == C_KEY)
	{
		change_color(fdf);
		design_map(fdf);
	}
	design_map(fdf);
	return (0);
}

void	rotation(int key, t_data *fdf)
{
	if (key == KEY_1)
		fdf -> rot_x = fdf -> rot_x + ROT;
	if (key == KEY_2)
		fdf -> rot_x = fdf -> rot_x - ROT;
	if (key == KEY_3)
		fdf -> rot_y = fdf -> rot_y + ROT;
	if (key == KEY_4)
		fdf -> rot_y = fdf -> rot_y - ROT;
	if (key == KEY_5)
		fdf -> rot_z = fdf -> rot_z + ROT;
	if (key == KEY_6)
		fdf -> rot_z = fdf -> rot_z - ROT;
}
