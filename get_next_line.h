/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralipran <ralipran@>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:33:46 by ralipran          #+#    #+#             */
/*   Updated: 2024/12/18 15:00:11 by ralipran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *s, int n, size_t len);
char	*ft_strchr(const char *s, int chardel);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_join_and_free(char *buf, char *buffer);
char	*ft_delete_line(char *buffer);
char	*ft_ret_line(char *buffer);
char	*ft_read_loop(int fd, char *data_treat, char *buffer);
char	*ft_read(int fd, char *data_treat);
char	*get_next_line(int fd);

#endif
