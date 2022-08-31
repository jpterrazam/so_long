/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-d <jpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 22:29:42 by jpaulo-d          #+#    #+#             */
/*   Updated: 2022/04/19 23:20:00 by jpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub_str;
	unsigned int	s_len;
	unsigned int	i;

	i = 0;
	s_len = ft_strlen(s);
	if (len > s_len - start && s_len - start > 0)
		len = s_len - start;
	else if (start >= s_len)
		len = 0;
	sub_str = (char *)malloc(len + 1);
	if (sub_str == NULL || s == NULL)
		return (NULL);
	if (start < s_len)
	{	
		while ((i < len) && s[start + i])
		{
			sub_str[i] = s[start + i];
			i++;
		}
	}
	sub_str[i] = '\0';
	return (sub_str);
}
