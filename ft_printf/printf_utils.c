/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sma <sma@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 16:18:35 by sma               #+#    #+#             */
/*   Updated: 2021/05/11 17:31:38 by sma              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_option					*init_opt(t_option *opt)
{
	opt->dash = 0;
	opt->zero = 0;
	opt->width = 0;
	opt->pre = -1;
	opt->type = '\0';
	opt->negative = 0;
	opt->hash = 0;
	opt->rst = "";
	return (opt);
}

char						*put_base(t_option *opt, unsigned long long num)
{
	char					*hex;
	char					*base;
	unsigned long long		len;

	if (ft_strchr("xXp", opt->type))
		hex = opt->type == 'X' ? "0123456789ABCDEF" : "0123456789abcdef";
	len = ft_baselen(num);
	base = (char*)malloc(sizeof(char) * len + 1);
	base[len] = '\0';
	while (num > 15)
	{
		base[--len] = hex[num % 16];
		num = num / 16;
	}
	base[--len] = hex[num % 16];
	return (base);
}

unsigned long long			ft_baselen(unsigned long long num)
{
	unsigned long long		tmp;
	unsigned long long		len;

	len = 1;
	tmp = num;
	while (tmp > 15)
	{
		len++;
		tmp /= 16;
	}
	return (len);
}

int							ft_alloc(t_option *opt)
{
	opt->w_a = (char*)malloc(sizeof(char) * opt->width + 1);
	opt->w_a[opt->width] = '\0';
	if (opt->pre > -1)
	{
		opt->p_a = (char*)malloc(sizeof(char) * opt->pre + 1);
		opt->p_a[opt->pre] = '\0';
	}
	return (0);
}

void						ft_free_wp(t_option *opt)
{
	free(opt->w_a);
	if (opt->pre > -1)
		free(opt->p_a);
}
