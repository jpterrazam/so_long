/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-d <jpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 22:29:42 by jpaulo-d          #+#    #+#             */
/*   Updated: 2022/04/24 02:50:43 by jpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	l_n;

	l_n = n;
	if (l_n < 0)
	{
		ft_putchar_fd('-', fd);
		l_n = l_n * -1;
	}
	if (l_n >= 10)
		ft_putnbr_fd(l_n / 10, fd);
	ft_putchar_fd((l_n % 10) + '0', fd);
}
