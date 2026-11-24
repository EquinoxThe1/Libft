/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matduart <matduart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 16:10:42 by matduart          #+#    #+#             */
/*   Updated: 2026/10/30 17:17:47 by matduart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	srcl;
	size_t	dstl;

	srcl = count((char *)src);
	dstl = count(dst);
	i = 0;
	if (size <= dstl)
		return (size + srcl);
	while (src[i] != 0 && i < (size - dstl - 1))
	{
		dst[i + dstl] = src[i];
		i++;
	}
	dst[i + dstl] = 0;
	return (srcl + dstl);
}
