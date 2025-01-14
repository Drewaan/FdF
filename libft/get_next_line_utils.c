/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 13:34:34 by aamaya-g          #+#    #+#             */
/*   Updated: 2024/09/05 12:16:55 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_gnl(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin_gnl(char *deposit, const char *buffer)
{
	int		i;
	int		x;
	char	*str;

	if (!deposit)
	{
		deposit = (char *)malloc(1 * sizeof(char));
		deposit[0] = '\0';
	}
	if (!deposit || !buffer)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen_gnl(deposit) + ft_strlen_gnl(buffer) + 1));
	if (str == NULL)
		return (0);
	i = -1;
	x = 0;
	if (deposit)
		while (deposit[++i] != '\0')
			str[i] = deposit[i];
	while (buffer[x] != '\0')
		str[i++] = buffer[x++];
	str[ft_strlen_gnl(deposit) + ft_strlen_gnl(buffer)] = '\0';
	free (deposit);
	return (str);
}

char	*ft_strchr_gnl(const char *str, char character)
{
	int		i;
	char	c;

	if (!str)
		return (NULL);
	c = (char)character;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			return ((char *)&str[i]);
		}
		i++;
	}
	if (str[i] == c)
		return ((char *)&str[i]);
	return (NULL);
}
