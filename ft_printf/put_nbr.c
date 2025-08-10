/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_nbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sma <sma@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 20:11:23 by sma               #+#    #+#             */
/*   Updated: 2021/05/11 17:31:19 by sma              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void				check_dash(t_option *opt, int len, char *str)
{
	ft_memset(opt->p_a, '0', opt->pre);
	if (opt->negative == 1)
	{
		if (opt->zero == 0 || opt->dash == 1)
			opt->p_a = ft_strjoin_free("-", opt->p_a);
		ft_strlcpy(opt->p_a + (ft_strlen(opt->p_a) - len), str, len + 1);
	}
	else if (opt->negative == 0)
		ft_strlcpy(opt->p_a + (opt->pre - len), str, len + 1);
	if (opt->dash == 1)
		ft_memmove(opt->w_a, opt->p_a, ft_strlen(opt->p_a));
	else if (opt->dash == 0)
		ft_strlcpy(opt->w_a + (opt->width - ft_strlen(opt->p_a)),
					opt->p_a, ft_strlen(opt->p_a) + 1);
	opt->rst = opt->w_a;
	opt->count += write(1, opt->rst, opt->width);
	ft_free_wp(opt);
	free(str);
}

void				check_pre(t_option *opt, int len, char *str)
{
	if (opt->width >= opt->pre)
	{
		opt->pre -= opt->negative && opt->zero ? 1 : 0;
		if (opt->zero == 0)
			ft_memset(opt->w_a, ' ', opt->width);
		else
			ft_memset(opt->w_a, '0', opt->width);
		if (opt->negative && opt->zero && opt->dash == 0)
			opt->w_a[0] = '-';
		check_dash(opt, len, str);
	}
	else if (opt->width < opt->pre)
	{
		ft_memset(opt->p_a, '0', opt->pre);
		if (opt->negative == 1)
		{
			opt->p_a[0] = '-';
			ft_strlcpy(opt->p_a + (opt->pre - len), str, len + 1);
		}
		else
			ft_strlcpy(opt->p_a + (opt->pre - len), str, len + 1);
		opt->count += write(1, opt->p_a, opt->pre);
		ft_free_wp(opt);
		free(str);
	}
}

void				check_wid(t_option *opt, int len, char *str)
{
	len += ((opt->negative && opt->zero == 0) ||
		(opt->negative > 0 && opt->dash)) ? 1 : 0;
	if (opt->width > len)
	{
		if (opt->zero == 0)
			ft_memset(opt->w_a, ' ', opt->width);
		else
			ft_memset(opt->w_a, '0', opt->width + 1);
		if (opt->negative == 1 && opt->zero == 1)
			opt->w_a[0] = '-';
	}
	str = ((opt->negative && opt->zero == 0) ||
	(opt->negative && opt->dash)) ? ft_strjoin_free("-", str) : str;
	if (opt->dash == 1)
		ft_memmove(opt->w_a, str, len);
	else if (opt->dash == 0)
		ft_strlcpy(opt->w_a + (opt->width - len), str, len + 1);
	opt->rst = opt->w_a;
	opt->count += write(1, opt->rst, opt->width);
	free(str);
	ft_free_wp(opt);
}

void				write_len(t_option *opt, char *str, int len)
{
	if (opt->negative == 1)
	{
		opt->rst = "-";
		opt->rst = ft_strjoin_free(opt->rst, str);
	}
	else
		opt->rst = ft_strjoin_free(opt->rst, str);
	opt->count += write(1, opt->rst, len + opt->negative);
	free(opt->rst);
	ft_free_wp(opt);
}

void				check_len(t_option *opt, int num)
{
	int				len;
	char			*str;
	char			*tmp;

	tmp = ft_itoa(num);
	str = (num == 0 && opt->pre == 0) ? ft_strdup("") : ft_strtrim(tmp, "-");
	len = (num == 0 && opt->pre == 0) ? 0 : (int)ft_strlen(str);
	opt->negative = (num < 0) ? 1 : 0;
	opt->pre += opt->pre >= len && opt->pre >= opt->width ? opt->negative : 0;
	if (ft_alloc(opt) < 0)
		return ;
	if (len >= opt->width && len >= opt->pre)
		write_len(opt, str, len);
	else if (len < opt->pre)
		check_pre(opt, len, str);
	else if (len >= opt->pre)
		check_wid(opt, len, str);
	free(tmp);
}
