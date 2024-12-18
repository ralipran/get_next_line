/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralipran <ralipran@>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:33:38 by ralipran          #+#    #+#             */
/*   Updated: 2024/12/18 15:03:17 by ralipran         ###   ########.fr       */
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

char	*ft_read_loop(int fd, char *data_treat, char *buffer)
{
	int	byte_read;
	int	is_nl_found;

	byte_read = 1;
	is_nl_found = 0;
	while (byte_read > 0 && !is_nl_found)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
			return (NULL);
		buffer[byte_read] = 0;
		data_treat = ft_join_and_free(data_treat, buffer);
		if (!data_treat)
			return (NULL);
		if (byte_read == 0)
			is_nl_found = 0;
		else if (ft_strchr(data_treat, '\n') != NULL)
			is_nl_found = 1;
	}
	return (data_treat);
}

char	*ft_read(int fd, char *data_treat)
{
	char	*buffer;
	char	*new_data_treat;

	if (!data_treat)
		data_treat = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
	{
		free(data_treat);
		return (NULL);
	}
	new_data_treat = ft_read_loop(fd, data_treat, buffer);
	free(buffer);
	if (!new_data_treat)
		free(data_treat);
	return (new_data_treat);
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
