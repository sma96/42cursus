/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sma <sma@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 16:00:35 by sma               #+#    #+#             */
/*   Updated: 2021/07/20 17:14:40 by sma              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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

void	printf_status(t_philo *philo, long long time, char *str)
{
	t_status		*status;
	char			*t;
	char			*id;

	status = philo->status;
	id = ft_itoa(philo->id);
	t = ft_itoa((int)(time - status->start_time));
	sem_wait(status->message);
	write(1, t, ft_strlen(t));
	write(1, " ms", 3);
	write(1, "\t\t", 2);
	write(1, id, ft_strlen(id));
	write(1, "   ", 3);
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	sem_post(status->message);
}
