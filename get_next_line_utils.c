/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralipran <ralipran@>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:33:31 by ralipran          #+#    #+#             */
/*   Updated: 2024/11/30 21:09:04 by ralipran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*memory;
	size_t	total_size;
	size_t	i;

	if (count == 0 || size == 0)
		return (NULL);
	total_size = count * size;
	memory = malloc(total_size);
	if (!memory)
		return (NULL);
	i = 0;
	while (i < total_size)
	{
		memory[i] = 0;
		i++;
	}
	return (memory);
}

char	*ft_strchr(const char *s, int chardel)
{
	char	*str;

	str = (char *)s;
	while (*str != chardel && *str != 0)
		str++;
	if (*str == chardel)
		return (str);
	else
		return (NULL);
}

char	*ft_free(char *buf, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(buf, buffer);
	if (!temp)
	{
		free(temp);
		return (NULL);
	}
	free(buf);
	return (temp);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*joined;
	int		total_size;
	int		i;
	int		j;

	total_size = ft_strlen(s1) + ft_strlen(s2);
	joined = malloc(sizeof(char) * (total_size + 1));
	if (!joined || !s1 || !s2)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		joined[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		joined[i] = s2[j];
		i++;
		j++;
	}
	joined[i] = '\0';
	return (joined);
}
