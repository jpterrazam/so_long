/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-d <jpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 22:29:42 by jpaulo-d          #+#    #+#             */
/*   Updated: 2022/04/19 21:14:41 by jpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_int_len(long int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*c_n;
	int			len;
	long int	l_n;

	l_n = n;
	len = ft_int_len(l_n);
	c_n = (char *)malloc(sizeof(char) * (len + 1));
	if (!(c_n))
		return (NULL);
	c_n[len--] = '\0';
	if (l_n < 0)
	{
		c_n[0] = '-';
		l_n = l_n * -1;
	}	
	if (l_n == 0)
		c_n[len--] = '0';
	while (l_n != 0)
	{
		c_n[len--] = (l_n % 10) + '0';
		l_n = (l_n / 10);
	}
	return (c_n);
}
