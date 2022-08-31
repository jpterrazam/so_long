/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-d <jpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 22:29:42 by jpaulo-d          #+#    #+#             */
/*   Updated: 2022/04/24 02:53:16 by jpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char delim)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (*str == delim)
			in_word = 0;
		else if (in_word == 0)
		{
			in_word = 1;
			count++;
		}
		str++;
	}
	return (count);
}

static char	*word_dup(const char *str, int start, int end)
{
	char	*word;

	word = ft_calloc((end - start + 1), sizeof(char));
	if (!word)
		return (NULL);
	word = ft_memcpy(word, &str[start], end - start);
	return (word);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	i;
	int				w_start;
	int				w_index;
	char			**words;

	words = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!s || !words)
		return (NULL);
	i = 0;
	w_start = -1;
	w_index = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && w_start == -1)
			w_start = i;
		else if (w_start != -1 && (s[i] == c || s[i] == '\0'))
		{
			words[w_index++] = word_dup(s, w_start, i);
			w_start = -1;
		}
		i++;
	}
	words[w_index] = NULL;
	return (words);
}
