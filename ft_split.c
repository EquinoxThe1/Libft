/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matduart <matduart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 13:19:27 by matduart          #+#    #+#             */
/*   Updated: 2026/11/05 17:22:18 by matduart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char delimiter)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != delimiter && (i == 0 || s[i - 1] == delimiter))
			count++;
		i++;
	}
	return (count);
}

static int	splitter(char **to_put, const char *to_split, char delimiter)
{
	size_t			i;
	unsigned int	start;
	size_t			word;

	i = 0;
	word = 0;
	while (to_split[i])
	{
		if (to_split[i] != delimiter)
		{
			start = i;
			while (to_split[i] && to_split[i] != delimiter)
				i++;
			to_put[word] = ft_substr(to_split, start, i - start);
			if (!to_put[word])
				return (0);
			word++;
		}
		else
			i++;
	}
	return (1);
}

static void	free_all(char **to_free)
{
	size_t	i;

	i = 0;
	while (to_free[i])
		free(to_free[i++]);
	free(to_free);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	if (!s)
		return (NULL);
	split = malloc(sizeof(char *) * (1 + count_words(s, c)));
	if (!split)
		return (NULL);
	if (!splitter(split, s, c))
	{
		free_all(split);
		return (NULL);
	}
	split[count_words(s, c)] = NULL;
	return (split);
}
