/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sma <sma@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 22:27:26 by sma               #+#    #+#             */
/*   Updated: 2021/02/11 17:04:40 by sma              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	size;

	if (!s)
		return (0);
	if (!(substr = (char*)malloc(sizeof(char) * len + 1)))
		return (0);
	size = ft_strlen((char*)s);
	if (start >= size)
	{
		substr[0] = 0;
		return (substr);
	}
	ft_strlcpy(substr, (char*)(s + start), len + 1);
	return (substr);
}
