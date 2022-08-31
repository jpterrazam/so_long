/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-d <jpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 22:29:42 by jpaulo-d          #+#    #+#             */
/*   Updated: 2022/06/22 19:56:08 by jpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_int_len(unsigned int n, int n_base)
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

int	check_base(char *base)
{
	char	*curr;
	int		i;
	int		j;

	curr = base;
	if (ft_strlen(base) <= 1)
		return (0);
	while (*curr)
	{
		if (*curr == '-' || *curr == '+' || *curr <= ' ')
			return (0);
		curr++;
	}
	i = 0;
	while (i < curr - base)
	{
		j = i + 1;
		while (j < curr - base)
			if (base[i] == base[j++])
				return (0);
		i++;
	}
	return (ft_strlen(base));
}

char	*ft_itoa_base(unsigned int n, char *base)
{
	char	*c_n;
	int		len;
	int		n_base;

	n_base = check_base(base);
	len = ft_int_len(n, n_base);
	c_n = (char *)malloc(sizeof(char) * (len + 1));
	if (!(c_n))
		return (NULL);
	c_n[len--] = '\0';
	if (n == 0)
		c_n[len--] = base[0];
	while (n != 0)
	{
		c_n[len--] = base[n % n_base];
		n = (n / n_base);
	}
	return (c_n);
}
