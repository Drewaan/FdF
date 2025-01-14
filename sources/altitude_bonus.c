/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   altitude_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 03:04:10 by aamaya-g          #+#    #+#             */
/*   Updated: 2024/12/04 03:07:27 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	altitude(int key, t_data *fdf)
{
	if (key == UP_KEY)
	{
		if (fdf -> ff < 10)
			fdf -> ff = fdf -> ff + FF;
	}
	if (key == DOWN_KEY)
	{
		if (fdf -> ff > 0)
			fdf -> ff = fdf -> ff - FF;
	}
}
