/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:28:51 by aamaya-g          #+#    #+#             */
/*   Updated: 2024/05/16 11:48:15 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*i;

	i = b;
	while (len > 0)
	{
		*i = c;
		i++;
		len--;
	}
	return (b);
}
/*
int main()
{
	char x[15];
	ft_memset(x, 'A', 14);
	printf("%s",x );
	return (0);
}
*/