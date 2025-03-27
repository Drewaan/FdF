/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:52:30 by aamaya-g          #+#    #+#             */
/*   Updated: 2025/01/28 16:08:58 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n-- > 0)
		*p++ = 0;
}

/* int main(void)
{
	char str[10] = "Hello";
	
	printf("Antes: %s\n", str);
	
	ft_bzero(str, sizeof(str));
	
	printf("Después: %s\n", str);
	
	return 0;
} */