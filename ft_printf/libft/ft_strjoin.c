/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sma <sma@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 15:40:05 by sma               #+#    #+#             */
/*   Updated: 2021/05/10 20:59:38 by sma              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*js;
	size_t	i;
	size_t	s1len;
	size_t	s2len;

	i = 0;
	if (!s1)
		return ((char *)s1);
	if (!s2)
		return ((char *)s2);
	s1len = ft_strlen((char*)s1);
	s2len = ft_strlen((char*)s2);
	if (!(js = (char*)malloc(sizeof(char) * (s1len + s2len + 1))))
		return (NULL);
	js[s1len + s2len] = '\0';
	while (*s1)
		js[i++] = *s1++;
	while (*s2)
		js[i++] = *s2++;
	return (js);
}
