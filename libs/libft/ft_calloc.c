/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-d <jpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 22:29:42 by jpaulo-d          #+#    #+#             */
/*   Updated: 2022/04/19 23:24:44 by jpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n_block, size_t size)
{
	void		*mem_alloc;
	long int	test_alloc;

	test_alloc = n_block * size;
	if (n_block != 0 && (test_alloc / n_block != size))
		return (NULL);
	mem_alloc = (void *)malloc (n_block * size);
	if (mem_alloc == NULL)
		return (NULL);
	ft_bzero(mem_alloc, n_block * size);
	return (mem_alloc);
}
