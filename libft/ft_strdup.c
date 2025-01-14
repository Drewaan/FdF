/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:59:40 by aamaya-g          #+#    #+#             */
/*   Updated: 2024/05/16 11:48:57 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;
	int		i;

	dst = (char *) malloc(ft_strlen(s1) + 1);
	i = 0;
	if (s1 == NULL)
	{
		return (NULL);
	}
	if (dst == NULL)
	{
		return (NULL);
	}
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}
