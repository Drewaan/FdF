/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:41:43 by aamaya-g          #+#    #+#             */
/*   Updated: 2024/11/13 12:42:02 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strchrbs(const char	*str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(const char *str, const char *base)
{
	int	number;
	int	sign;

	number = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			sign = sign * -1;
	}
	while (ft_strchrbs(base, *str) != -1
		|| ft_strchrbs(base, ft_toupper(*str)) != -1)
	{
		if (ft_strchrbs(base, *str) != -1)
			number = number * ft_strlen(base) + ft_strchrbs(base, *str++);
		else
			number = number * ft_strlen(base) + ft_strchrbs(base, ft_toupper(*str++));
	}
	return (number * sign);
}