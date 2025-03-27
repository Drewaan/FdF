/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 02:58:27 by aamaya-g          #+#    #+#             */
/*   Updated: 2025/01/28 13:57:30 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	zoom(int key, t_data *fdf)
{
	if (key == MINUS_KEY)
	{
		if (fdf -> zoom > 0)
			fdf -> zoom = fdf -> zoom - ZOOM;
	}
	if (key == PLUS_KEY)
	{
		if (fdf -> zoom < (float)INT_MAX)
			fdf -> zoom = fdf -> zoom + ZOOM;
	}
}
