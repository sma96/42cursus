/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sma <sma@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 16:00:35 by sma               #+#    #+#             */
/*   Updated: 2021/07/23 14:48:33 by sma              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

int	ft_isspace(const char *c)
{
	int				i;

	i = 0;
	while (c[i] == '\t' || c[i] == '\v' || c[i] == '\f' \
			|| c[i] == '\r' || c[i] == '\n' || c[i] == ' ')
		i++;
	return (i);
}

int	ft_atoi(const char *c)
{
	int				i;
	long long		num;
	int				sign;

	i = ft_isspace(c);
	num = 0;
	sign = 1;
	if (c[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (c[i] == '+')
		i++;
	while ('0' <= c[i] && c[i] <= '9')
	{
		num = num * 10 + (c[i] - '0');
		if (2147483647 < num * sign)
			return (-1);
		else if (num * sign < -2147483648)
			return (0);
		i++;
	}
	return ((num * sign));
}

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	printf_status(t_philo *philo, char *str)
{
	t_status		*status;

	status = philo->status;
	pthread_mutex_lock(&status->message);
	printf("%2lld ms %5d %2s\n", get_time() - status->start_time, \
												philo->id, str);
	pthread_mutex_unlock(&status->message);
}
