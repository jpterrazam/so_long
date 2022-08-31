/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-d <jpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 22:16:53 by jpaulo-d          #+#    #+#             */
/*   Updated: 2022/08/29 22:02:19 by jpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_get_first_line(char *str);
static char	*ft_get_leftover(char *str, int n);

char	*ft_get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*stock;
	int			chars_read;

	chars_read = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (chars_read > 0 && !ft_strchr(stock, '\n'))
	{
		chars_read = read(fd, buffer, BUFFER_SIZE);
		if (chars_read < 0)
			return (free(buffer), NULL);
		buffer[chars_read] = '\0';
		stock = ft_strjoin(stock, buffer);
	}
	line = ft_get_first_line(stock);
	stock = ft_get_leftover(stock, ft_strlen(line));
	return (free(buffer), line);
}

static char	*ft_get_first_line(char *str)
{
	char	*first_line;
	int		len;
	int		j;

	len = 0;
	j = 0;
	if (!str || !str[0])
		return (NULL);
	while (str[len] && str[len] != '\n')
		len++;
	if (str[len] == '\n')
		len++;
	first_line = (char *)malloc((len + 1) * sizeof(char));
	if (!first_line)
		return (NULL);
	while (j < len)
	{
		first_line[j] = str[j];
		j++;
	}
	first_line[j] = '\0';
	return (first_line);
}

static char	*ft_get_leftover(char *str, int n)
{
	char	*leftover;
	int		i;

	i = 0;
	if (!str || !str[0])
		return (free(str), NULL);
	leftover = (char *)malloc((ft_strlen(str) - n + 1) * sizeof(char));
	if (!leftover)
		return (NULL);
	while (str[n])
		leftover[i++] = str[n++];
	leftover[i] = '\0';
	free(str);
	return (leftover);
}
