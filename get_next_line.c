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
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

char	*ft_read(int fd, char *residual)
{
	char	*buffer;
	int		byte_read;
	int		is_line_found;

	if (!residual)
		residual = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
	{
		free(residual);
		return (NULL);
	}
	byte_read = 1;
	is_line_found = 0;
	while (byte_read > 0 && !is_line_found)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buffer);
			free(residual);
			return (NULL);
		}
		buffer[byte_read] = 0;
		residual = ft_free(residual, buffer);
		if (!residual)
			return (NULL);
		is_line_found = (byte_read == 0 || ft_strchr(residual, '\n') != NULL);
	}
	free(buffer);
	return (residual);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
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

/*char	*ft_read(int fd, char *residual)
{
	char	*buffer;
	int		byte_read;

	if (!residual)
		residual = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
	{
		free(residual);
		return (NULL);
	}
	byte_read = 1;
	while (byte_read > 0 && !ft_strchr(buffer, '\n'))
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buffer);
			free(residual);
			return (NULL);
		}
		buffer[byte_read] = 0;
		residual = ft_free(residual, buffer);
		if (!residual)
		{
			free(residual);
			return (NULL);
		}
	}
	free(buffer);
	return (residual);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = ft_read(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_ret_line(buffer);
	buffer = ft_delete_line(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*residual;
	char		*line;
	char		*nl_position;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	printf("fd valide\n");
	residual = read_and_update(fd, residual);
	if (residual == NULL)
		return (NULL);
	printf("fd valide\n");
	nl_position = find_new_line(residual);
	if (nl_position == NULL)
	{
		line = ft_strdup(residual);
		free(residual);
		residual = NULL;
		return (line);
	}
	line = ft_substr(residual, 0, nl_position - residual + 1);
	residual = ft_strdup(nl_position + 1);
	return (line);
}*/

/*#include <fcntl.h>

int	main(void)
{
	int fd = open("bjr.txt", O_RDONLY);
	if (fd == -1)
	{
    	printf("Erreur lors de l'ouverture du fichier\n");
        return 1;
	}
	printf("%s\n", get_next_line(fd));
	return (0);
}*/
