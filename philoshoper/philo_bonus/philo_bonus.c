/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sma <sma@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:59:12 by sma               #+#    #+#             */
/*   Updated: 2021/07/20 16:27:02 by sma              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

char	*ft_transf(long long n, char *str, int len)
{
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
		while (len >= 1)
		{
			str[len] = '0' + n % 10;
			n = n / 10;
			len--;
		}
	}
	else
	{
		while (len >= 0)
		{
			str[len] = '0' + n % 10;
			n = n / 10;
			len--;
		}
	}
	return (str);
}

int	ft_strlen2(long long n)
{
	int			len;
	long long	a;

	a = n;
	len = 0;
	if (a <= 0)
	{
		len++;
		a *= -1;
	}
	while (a > 0)
	{
		a = a / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int			len;
	char		*str;

	len = ft_strlen2(n);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	str[len] = '\0';
	len--;
	return (ft_transf(n, str, len));
}

int	check_arg(char **argv)
{
	int			i;
	int			j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_status	status;

	if (argc > 6 || argc < 5)
	{
		write(1, "error\n", 6);
		return (0);
	}
	if (check_arg(argv))
	{
		write(1, "error\n", 6);
		return (0);
	}
	if (init_s(&status, argv))
	{
		write(1, "error\n", 6);
		return (0);
	}
	create_tp(&status);
	return (0);
}
