/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matduart <matduart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 18:06:09 by matduart          #+#    #+#             */
/*   Updated: 2026/11/01 18:31:35 by matduart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i] == little[j] && little[j] && i < len)
		{
			i++;
			j++;
		}
		if (little[j] == 0)
		{
			i -= j;
			return ((char *)&big[i]);
		}
		else
			i -= j;
		i++;
	}
	return (NULL);
}
