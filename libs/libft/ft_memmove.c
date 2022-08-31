/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-d <jpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 22:29:42 by jpaulo-d          #+#    #+#             */
/*   Updated: 2022/04/24 01:46:40 by jpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	char			*cast_src;
	char			*cast_dest;

	cast_src = (char *)src;
	cast_dest = (char *)dest;
	if (cast_dest > cast_src)
	{
		i = n;
		while (i > 0)
		{
			i--;
			cast_dest[i] = cast_src[i];
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			cast_dest[i] = cast_src[i];
			i++;
		}
	}
	return (dest);
}
