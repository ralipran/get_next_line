/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralipran <ralipran@>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:33:38 by ralipran          #+#    #+#             */
/*   Updated: 2024/11/30 21:01:14 by ralipran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_ret_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] || buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*ft_delete_line(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(buffer) - i), sizeof(char));
	i++;
	j = 0;
	while (buffer[i])
	{
		line[j] = buffer[i];
		i++;
		j++;
	}
	free(buffer);
	return (line);
}

char	*ft_read_loop(int fd, char *residual, char *buffer)
{
	int	byte_read;
	int	is_line_found;

	byte_read = 1;
	is_line_found = 0;
	while (byte_read > 0 && !is_line_found)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
			return (NULL);
		buffer[byte_read] = 0;
		residual = ft_free(residual, buffer);
		if (!residual)
			return (NULL);
		is_line_found = (byte_read == 0 || ft_strchr(residual, '\n') != NULL);
	}
	return (residual);
}

char	*ft_read(int fd, char *residual)
{
	char	*buffer;
	char	*new_residual;

	if (!residual)
		residual = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
	{
		free(residual);
		return (NULL);
	}
	new_residual = ft_read_loop(fd, residual, buffer);
	free(buffer);
	if (!new_residual)
		free(residual);
	return (new_residual);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = ft_read(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_ret_line(buffer);
	buffer = ft_delete_line(buffer);
	return (line);
}
