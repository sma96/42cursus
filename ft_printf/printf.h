/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sma <sma@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 19:58:15 by sma               #+#    #+#             */
/*   Updated: 2021/05/11 17:31:36 by sma              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include "./libft/libft.h"

typedef struct			s_option
{
	int					dash;
	int					zero;
	int					hash;
	int					width;
	int					pre;
	int					count;
	int					negative;
	char				type;
	char				*ox;
	char				*w_a;
	char				*p_a;
	char				*rst;
}						t_option;

/*
** parsing 함수
*/
int						ft_printf(const char *format, ...);
int						check_type(const char *format, va_list ap,\
												t_option *opt);
const char				*ft_format(const char *format, va_list ap,\
												t_option *opt);
void					check_wid_pre(const char format, va_list ap,\
												t_option *opt);
/*
** put_nbr 함수
*/
void					check_dash(t_option *opt,
												int len, char *str);
void					check_pre(t_option *opt,
												int len, char *str);
void					check_wid(t_option *opt,
												int len, char *str);
void					write_len(t_option *opt,
												char *str, int len);
void					check_len(t_option *opt, int num);
/*
** put_char 함수
*/
void					ft_putchar(t_option *opt, char c);
void					ft_putstr(t_option *opt, char *str);
void					put_char(t_option *opt, va_list ap);
/*
** put_base 함수
*/
void					check_baselen(t_option *opt, unsigned long long n);
void					check_base_w(t_option *opt,
												int len, char *str);
void					check_base_p(t_option *opt,
												int len, char *str);
void					base_dash(t_option *opt,
												int len, char *str);
char					*put_base(t_option *opt, unsigned long long num);
/*
** utils 함수
*/
int						ft_atoi_2(const char c);
void					all_free(t_option *opt);
unsigned long long		ft_baselen(unsigned long long num);
int						ft_alloc(t_option *opt);
t_option				*init_opt(t_option *opt);
char					*ft_strjoin_free(char *rst, char *str);
void					ft_free_wp(t_option *opt);

#endif
