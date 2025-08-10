/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sma <sma@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 23:43:04 by sma               #+#    #+#             */
/*   Updated: 2021/02/11 16:48:30 by sma              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strdup(const char *src)
{
	char		*msrc;
	size_t		srclen;
	size_t		i;

	srclen = ft_strlen((char*)src);
	msrc = (char*)malloc(sizeof(char) * srclen + 1);
	if (msrc == 0)
		return (0);
	i = 0;
	ft_strlcpy(msrc, (char*)src, srclen + 1);
	return (&msrc[0]);
}
