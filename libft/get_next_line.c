/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 13:34:29 by aamaya-g          #+#    #+#             */
/*   Updated: 2024/09/05 12:14:53 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*excess(char *deposit)
{
	char	*excess;
	int		i;
	int		x;

	i = 0;
	x = 0;
	while (deposit[i] != '\0' && deposit[i] != '\n')
		i++;
	if (!deposit[i])
	{
		free (deposit);
		return (NULL);
	}
	excess = malloc(sizeof(char) * (ft_strlen_gnl(deposit) - i + 1));
	if (!excess)
		return (NULL);
	i++;
	while (deposit[i])
	{
		excess[x++] = deposit[i++];
	}
	excess[x] = '\0';
	free(deposit);
	return (excess);
}

char	*create_line(char *deposit)
{
	char	*line;
	int		i;

	i = 0;
	if (!deposit[0])
		return (NULL);
	while (deposit[i] && deposit[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (deposit[i] && deposit[i] != '\n')
	{
		line[i] = deposit[i];
		i++;
	}
	if (deposit[i] == '\n')
	{
		line[i] = deposit[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*deposit[4096];
	char		buffer[BUFFER_SIZE +1];
	int			readbytes;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	readbytes = 1;
	while (!ft_strchr_gnl(deposit[fd], '\n') && readbytes != 0)
	{
		readbytes = read(fd, buffer, BUFFER_SIZE);
		if (readbytes == -1)
			return (NULL);
		buffer[readbytes] = '\0';
		deposit[fd] = ft_strjoin_gnl(deposit[fd], buffer);
	}
	if (!deposit[fd])
		return (NULL);
	line = create_line(deposit[fd]);
	deposit[fd] = excess(deposit[fd]);
	return (line);
}
/* int	main(void)
{
	int		fd, fd1, fd2;
	char	*line;

	fd = open("text.txt", O_RDONLY);
	fd1 = open("text1.txt", O_RDONLY);
	fd2 = open("text2.txt", O_RDONLY);
	if (fd == -1 || fd1 == -1 || fd2 == -1)
		return (perror("open"), 1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		printf ("%s", line);
		free(line);
	}
	printf("\n");
	while (1)
	{
		line = get_next_line(fd1);
		if (!line)
			break ;
		printf("%s", line);
		free(line);
	}
	printf("\n");
	while (1)
	{
		line = get_next_line(fd2);
		if (!line)
			break ;
		printf("%s", line);
		free(line);
	}
	close(fd);
	close(fd1);
	close(fd2);
	return (0);
}  */