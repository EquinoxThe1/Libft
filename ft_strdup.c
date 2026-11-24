/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matduart <matduart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 19:37:46 by matduart          #+#    #+#             */
/*   Updated: 2026/11/01 19:07:55 by matduart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		size;
	int		i;

	size = ft_strlen(s);
	dup = malloc(size + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i <= size)
	{
		dup[i] = s[i];
		i++;
	}
	return (dup);
}
