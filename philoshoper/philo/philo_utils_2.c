/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sma <sma@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 14:00:08 by sma               #+#    #+#             */
/*   Updated: 2021/07/23 14:45:39 by sma              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_mutex_free(t_status *status)
{
	int			i;

	i = 0;
	usleep(1000);
	while (i < status->philo_num)
		pthread_mutex_destroy(&status->fork[i++]);
	pthread_mutex_destroy(&status->message);
	pthread_mutex_destroy(&status->died);
	pthread_mutex_destroy(&status->exit);
	free(status->philo);
	free(status->fork);
}

void	destroy_mutex_all(t_status *status)
{
	int			i;

	i = 0;
	while (i < status->philo_num)
		pthread_mutex_destroy(&status->fork[i++]);
	pthread_mutex_destroy(&status->message);
	pthread_mutex_destroy(&status->died);
	pthread_mutex_destroy(&status->exit);
}

void	sleep_think(t_philo *philo, t_status *status)
{
	printf_status(philo, "is sleeping");
	usleep(status->tts * 1000);
}

void	ft_usleep(int time)
{
	long long	start;

	start = get_time();
	while (get_time() < (start + time))
		usleep(100);
}
