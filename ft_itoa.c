/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matduart <matduart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 13:41:46 by matduart          #+#    #+#             */
/*   Updated: 2026/11/01 14:35:30 by matduart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*str;
	size_t	size;
	long	temp;

	size = (n <= 0);
	temp = n;
	while ((n != 0) && ++size)
		n = (n / 10);
	str = malloc(size + 1);
	if (!str)
		return (NULL);
	str[size] = 0;
	if (temp < 0)
	{
		str[0] = '-';
		temp = -temp;
	}
	if (temp == 0)
		str[0] = '0';
	while (temp > 0)
	{
		str[--size] = (temp % 10) + '0';
		temp = (temp / 10);
	}
	return (str);
}
