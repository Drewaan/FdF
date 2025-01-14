/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:41:57 by aamaya-g          #+#    #+#             */
/*   Updated: 2024/09/10 20:04:40 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_pointer(void *ptr, int len)
{
	if (ptr == NULL)
		len = print_str("(nil)", len);
	else
	{
		len = print_str("0x", len);
		len = print_hex((size_t)ptr, len, 'p');
	}
	return (len);
}
