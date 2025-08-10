/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sma <sma@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 15:16:00 by sma               #+#    #+#             */
/*   Updated: 2021/03/01 16:40:08 by sma              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char		**ft_free(char **ss, int len)
{
	int		i;

	i = 0;
	while (i <= len)
	{
		free(ss[i]);
		i++;
	}
	free(ss);
	return (NULL);
}

int			ft_strcpy2(char **ss, char *str, char c, int idx)
{
	int		i;

	i = 0;
	while (str[i] != c && str[i] != '\0')
		i++;
	if (!(ss[idx] = (char*)malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (*str != c && *str != '\0')
	{
		ss[idx][i] = *str;
		str++;
		i++;
	}
	ss[idx][i] = '\0';
	return (1);
}

int			ft_count(char *str, char c)
{
	int		i;
	int		count;
	int		flag;
	char	*tri;

	if (!(*str))
		return (0);
	i = 0;
	count = 0;
	flag = 0;
	tri = ft_strtrim(str, &c);
	while (tri[i])
	{
		flag = 1;
		if (tri[i] == c && tri[i + 1] != c)
			count++;
		i++;
	}
	if (flag)
		count++;
	return (count);
}

char		**ft_split(char *str, char c)
{
	int		i;
	int		count;
	char	**ss;

	if (!str)
		return (NULL);
	i = 0;
	count = ft_count(str, c);
	if (!(ss = (char**)malloc(sizeof(char*) * (count + 1))))
		return (NULL);
	ss[count] = NULL;
	while (i < count)
	{
		while (*str == c)
			str++;
		if (ft_strcpy2(ss, str, c, i) == 0)
			return (ft_free(ss, i));
		while (*str != c && *str != '\0')
			str++;
		i++;
	}
	return (ss);
}
