/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sma <sma@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 23:41:08 by sma               #+#    #+#             */
/*   Updated: 2021/07/05 15:50:17 by sma              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t size)
{
	unsigned char	*temp;
	size_t			i;

	temp = (unsigned char *)ptr;
	i = 0;
	while (i++ < size)
	{
		*temp++ = (unsigned char)value;
	}
	return (ptr);
}
