/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sma <sma@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 23:45:12 by sma               #+#    #+#             */
/*   Updated: 2021/02/11 16:45:46 by sma              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (!dest || !src)
		return (0);
	while (src[i])
		i++;
	if (size != 0)
	{
		while (j < size - 1 && src[j])
		{
			dest[j] = src[j];
			++j;
		}
		dest[j] = '\0';
	}
	return (i);
}
