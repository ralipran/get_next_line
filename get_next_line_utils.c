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
	char	*residual;
	size_t	total_size;
	size_t	i;

	if (count == 0 || size == 0)
		return (NULL);
	total_size = count * size;
	residual = malloc(total_size);
	if (!residual)
		return (NULL);
	i = 0;
	while (i < total_size)
	{
		residual[i] = 0;
		i++;
	}
	return (residual);
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
	int		total_size;
	char	*residual;
	int		i;
	int		j;

	i = 0;
	total_size = ft_strlen(s1) + ft_strlen(s2);
	residual = malloc(sizeof(char) * (total_size + 1));
	if (!residual || !s1 || !s2)
		return (NULL);
	while (s1[i])
	{
		residual[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		residual[i] = s2[j];
		i++;
		j++;
	}
	residual[total_size] = 0;
	return (residual);
}

/*char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	printf("strjoin\n");
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (s1 == NULL)
		return (NULL);
	else if (s2 == NULL)
		return (NULL);
	printf("strjoin\n");
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	while (s1[i++])
		str[i] = s1[i];
	j = 0;
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	printf("%s\n", str);
	return (str);
}

char	*find_new_line(const char *str)
{
	int	i;

	i = 0;
	printf("fnl\n");
	if (str == NULL)
	{
		printf("residual = NULL\n");
		return (NULL);
	}
	while (str[i])
	{
		if (str[i] == '\n')
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	int		i;
	int		s_len;
	char	*str;

	s_len = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (s_len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*str;

	i = 0;
	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		str = (char *)malloc(sizeof(char) * 1);
		if (str == NULL)
			return (NULL);
		str[0] = 0;
		return (str);
	}
	if (len > s_len - start)
		len = s_len - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (i < len)
		str[i++] = s[start++];
	str[i] = 0;
	return (str);
}

char	*ft_strlcpy_II(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = 0;
	while (src[src_len])
		src_len++;
	if (dstsize == 0)
		return (src_len);
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
char	*ft_strdup(const char *s)
{
	int		i;
	int		s_len;
	char	*str;

	i = 0;
	s_len = ft_strlen(s);
	while (s[i])
		i++;
	str = (char *)malloc(sizeof(*str) * (s_len + 1));
	if (str == NULL)
		return (NULL);
	while (i >= 0)
	{
		str[i] = s[i];
		i--;
	}
	return (str);
}*/
