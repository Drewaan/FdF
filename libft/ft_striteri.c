/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:08:54 by aamaya-g          #+#    #+#             */
/*   Updated: 2024/05/21 14:15:43 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	x;

	if (s == NULL || f == NULL)
	{
		return ;
	}
	x = 0;
	while (s[x] != '\0')
	{
		f(x, &s[x]);
		x++;
	}
}
