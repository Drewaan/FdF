/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:08:51 by aamaya-g          #+#    #+#             */
/*   Updated: 2025/01/28 14:26:23 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*arr;

	if (count && size && count > 2147483647 / size)
		return (NULL);
	arr = malloc(count * size);
	if (!arr)
		return (arr);
	ft_bzero(arr, count * size);
	return (arr);
}
