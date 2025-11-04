/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmuller <stmuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 15:24:52 by stmuller          #+#    #+#             */
/*   Updated: 2025/11/04 02:05:54 by stmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *buffer, char *buf)
{
	char	*tmp;

	tmp = ft_strjoin(buffer, buf);
	free(buffer);
	return (tmp);
}

char	*clear_buff(char *buffer_main)
{
	char	*new_buffer;
	int		i;
	int		j;

	i = 0;
	while (buffer_main[i] && buffer_main[i] != '\n')
		i++;
	if (!buffer_main[i])
	{
		free(buffer_main);
		return (NULL);
	}
	new_buffer = ft_calloc(ft_strlen(buffer_main) - i + 1, sizeof(char));
	i++;
	j = 0;
	while (buffer_main[i])
		new_buffer[j++] = buffer_main[i++];
	free(buffer_main);
	return (new_buffer);
}

char	*lines(char	*buffer_main)
{
	char	*line;
	int		i;

	if (!buffer_main[0])
		return (NULL);
	i = 0;
	while (buffer_main[i] && buffer_main[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer_main[i] && buffer_main[i] != '\n')
	{
		line[i] = buffer_main[i];
		i++;
	}
	if (buffer_main[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*reader(int fd, char *buffer_main)
{
	char	*buffer;
	int		read_r;

	if (!buffer_main)
		buffer_main = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	read_r = 1;
	while (read_r > 0)
	{
		read_r = read(fd, buffer, BUFFER_SIZE);
		if (read_r == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_r] = 0;
		buffer_main = ft_free(buffer_main, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (buffer_main);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = reader(fd, buffer);
	if (!buffer)
		return (NULL);
	line = lines(buffer);
	buffer = clear_buff(buffer);
	return (line);
}
