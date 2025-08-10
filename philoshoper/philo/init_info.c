/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sma <sma@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 16:24:00 by sma               #+#    #+#             */
/*   Updated: 2021/07/23 20:07:23 by sma              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philo(t_status *status)
{
	int		i;

	i = 0;
	status->philo = (t_philo *)malloc(sizeof(t_philo) * status->philo_num);
	if (!(status->philo))
		return (0);
	while (i < status->philo_num)
	{
		status->philo[i].eat_count = 0;
		status->philo[i].id = i + 1;
		status->philo[i].l_fork = i;
		status->philo[i].r_fork = (i + 1) % status->philo_num;
		status->philo[i].status = status;
		i++;
	}
	return (1);
}

int	init_mutex(t_status *status)
{
	int		i;

	i = 0;
	status->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * \
					status->philo_num);
	while (i < status->philo_num)
	{
		if (pthread_mutex_init(&status->fork[i], NULL) == -1)
			return (1);
		i++;
	}
	if (pthread_mutex_init(&status->message, NULL) == -1)
		return (1);
	if (pthread_mutex_init(&status->died, NULL) == -1)
		return (1);
	if (pthread_mutex_init(&status->exit, NULL) == -1)
		return (1);
	return (0);
}

int	init_s(t_status *status, char **argv)
{
	status->philo_num = ft_atoi(argv[1]);
	status->ttd = ft_atoi(argv[2]);
	status->tte = ft_atoi(argv[3]);
	status->tts = ft_atoi(argv[4]);
	status->must_eat = -1;
	status->die = 0;
	if (argv[5])
		status->must_eat = ft_atoi(argv[5]);
	if (status->philo_num < 1 || status->philo_num > 199 || \
				status->ttd < 0 || status->tte < 0 || status->tts < 0 || \
							status->must_eat < -1 || status->must_eat == 0)
		return (1);
	if (init_mutex(status))
		return (1);
	if (!(init_philo(status)))
		return (1);
	return (0);
}
