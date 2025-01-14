/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 02:33:26 by aamaya-g          #+#    #+#             */
/*   Updated: 2024/12/04 02:51:29 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	translation(int key, t_data *fdf)
{
	if (key == W_KEY)
		fdf -> shift_y = fdf -> shift_y + TRANS;
	if (key == A_KEY)
		fdf -> shift_x = fdf -> shift_x + TRANS;
	if (key == S_KEY)
		fdf -> shift_y = fdf -> shift_y - TRANS;
	if (key == D_KEY)
		fdf -> shift_x = fdf -> shift_x - TRANS;
}
