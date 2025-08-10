/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sma <sma@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 18:00:23 by sma               #+#    #+#             */
/*   Updated: 2021/05/11 17:31:15 by sma              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char		*ft_strjoin_free(char *rst, char *str)
{
	char					*temp;
	char					*s;

	temp = str;
	s = ft_strjoin(rst, str);
	free(temp);
	return (s);
}

int			ft_atoi_2(const char c)
{
	long long		num;

	num = 0;
	num = num * 10 + (c - '0');
	return ((num));
}

void		ft_putchar(t_option *opt, char c)
{
	if (opt->dash == 1)
	{
		opt->count += write(1, &c, 1);
		while (--opt->width > 0)
			opt->count += write(1, " ", 1);
	}
	else if (opt->dash == 0)
	{
		while (--opt->width > 0)
			opt->count += write(1, " ", 1);
		opt->count += write(1, &c, 1);
	}
	ft_free_wp(opt);
}

void		ft_putstr(t_option *opt, char *str)
{
	int		len;

	if (str == NULL)
		str = "(null)";
	len = opt->pre == 0 ? 0 : ft_strlen(str);
	len = (len > opt->pre && opt->pre > -1) ? opt->pre : len;
	opt->width = opt->width > len ? opt->width - len : 0;
	if (opt->dash == 1)
	{
		opt->count += write(1, str, len);
		while (opt->width--)
			opt->count += write(1, " ", 1);
	}
	else if (opt->dash == 0)
	{
		while (opt->width--)
			opt->count += write(1, " ", 1);
		opt->count += write(1, str, len);
	}
	ft_free_wp(opt);
}

void		put_char(t_option *opt, va_list ap)
{
	int		len;
	char	*str;

	if (ft_alloc(opt) < 0)
		return ;
	if (opt->type == 'c')
		ft_putchar(opt, va_arg(ap, int));
	else if (opt->type == 's')
		ft_putstr(opt, va_arg(ap, char *));
	else if (opt->type == '%')
	{
		if (opt->pre > -1)
			free(opt->p_a);
		opt->pre = -1;
		len = 1;
		str = ft_strdup("%");
		if (len >= opt->width && len >= opt->pre)
			write_len(opt, str, len);
		else if (len < opt->pre)
			check_pre(opt, len, str);
		else if (len >= opt->pre)
			check_wid(opt, len, str);
	}
}
