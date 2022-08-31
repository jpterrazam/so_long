/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-d <jpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 22:29:42 by jpaulo-d          #+#    #+#             */
/*   Updated: 2022/06/22 20:31:56 by jpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_int_len(unsigned long long n, int n_base)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n = n / n_base;
	}
	return (len);
}

char	*ft_itoa_ptr(unsigned long long int n)
{
	char	*c_n;
	int		len;
	char	*base;

	base = "0123456789abcdef";
	len = ft_int_len(n, 16) + 2;
	c_n = (char *)malloc(sizeof(char) * (len + 1));
	if (!(c_n))
		return (NULL);
	c_n[0] = '0';
	c_n[1] = 'x';
	c_n[len--] = '\0';
	if (n == 0)
		c_n[len--] = base[0];
	while (n != 0)
	{
		c_n[len--] = base[n % 16];
		n = (n / 16);
	}
	return (c_n);
}
