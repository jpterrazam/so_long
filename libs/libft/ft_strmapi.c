/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-d <jpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 22:29:42 by jpaulo-d          #+#    #+#             */
/*   Updated: 2022/04/24 01:49:29 by jpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	s_len;
	char			*new_s;
	unsigned int	i;

	if (s == NULL || s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	new_s = malloc((s_len + 1) * sizeof(char));
	if (new_s == NULL)
		return (NULL);
	new_s[s_len] = '\0';
	i = 0;
	while (i < s_len)
	{
		new_s[i] = f(i, s[i]);
		i++;
	}
	return (new_s);
}
