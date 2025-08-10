/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_time_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sma <sma@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 16:27:02 by sma               #+#    #+#             */
/*   Updated: 2021/07/23 19:46:05 by sma              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	eat_dinner(t_philo *philo)
{
	t_status	*status;

	status = philo->status;
	sem_wait(status->fork);
	sem_wait(status->fork);
	printf_status(philo, get_time(), "has taken a fork");
	printf_status(philo, get_time(), "has taken a fork");
	philo->now_time = get_time();
	printf_status(philo, get_time(), "is eating");
	ft_usleep(status->tte);
	sem_post(status->fork);
	sem_post(status->fork);
	philo->eat_count++;
}

void	*check_die(void *phi)
{
	t_philo		*philo;
	t_status	*status;

	philo = (t_philo *)phi;
	status = philo->status;
	while (status->die == 0 && (status->must_eat > philo->eat_count || \
													status->must_eat == -1))
	{
		if ((get_time() - philo->now_time) > status->ttd && status->die == 0)
		{
			sem_wait(status->message);
			sem_wait(status->death);
			status->die = 1;
			printf("%2lld ms\t\t%d   %2s\n", get_time() - status->start_time, \
														philo->id, "died");
			sem_post(status->died);
		}
		usleep(100);
	}
	return (NULL);
}

void	process_act(t_status *status, t_philo *philo)
{
	pthread_t	check_d;

	philo->now_time = get_time();
	pthread_create(&check_d, NULL, check_die, (void *)philo);
	pthread_detach(check_d);
	while (1)
	{
		while (status->die == 0 && (status->must_eat > philo->eat_count || \
													status->must_eat == -1))
		{
			if (status->die == 0 && (status->must_eat > philo->eat_count || \
													status->must_eat == -1))
				eat_dinner(philo);
			if (status->must_eat <= philo->eat_count && status->must_eat != -1)
				sem_post(status->must_e);
			if (status->die == 0 && (status->must_eat > philo->eat_count || \
													status->must_eat == -1))
				sleep_think(philo, status);
			if (status->die == 0 && (status->must_eat > philo->eat_count || \
													status->must_eat == -1))
				printf_status(philo, get_time(), "is thinking");
		}
	}
}

void	*check_eat(void *sta)
{
	t_status	*status;
	int			i;

	status = (t_status *)sta;
	i = 0;
	while (i < status->philo_num)
	{	
		sem_wait(status->must_e);
		i++;
	}
	usleep(100);
	if (status->die == 0)
	{
		sem_wait(status->message);
		printf("\teveryone ate!\n");
		sem_post(status->died);
	}
	return (NULL);
}

int	create_tp(t_status *status)
{
	int			i;
	t_philo		*philo;

	i = 0;
	philo = status->philo;
	if (status->must_eat > -1)
		pthread_create(&status->check_e, NULL, check_eat, (void *)status);
	pthread_detach(status->check_e);
	pthread_create(&status->death_flag, NULL, check_flag, (void *)status);
	pthread_detach(status->death_flag);
	status->start_time = get_time();
	while (i < status->philo_num)
	{
		status->pid[i] = fork();
		if (status->pid[i] == 0)
			process_act(status, &philo[i]);
		i++;
		usleep(100);
	}
	while (status->die == 0)
		usleep(100);
	all_free_unlink(status);
	return (0);
}
