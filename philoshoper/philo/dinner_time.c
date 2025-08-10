/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sma <sma@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 16:27:02 by sma               #+#    #+#             */
/*   Updated: 2021/07/23 14:44:45 by sma              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat_dinner(t_philo *philo)
{
	t_status	*status;

	status = philo->status;
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&status->fork[philo->l_fork]);
		printf_status(philo, "has taken a fork");
		pthread_mutex_lock(&status->fork[philo->r_fork]);
		printf_status(philo, "has taken a fork");
	}
	else if (philo->id % 2 == 1)
	{
		pthread_mutex_lock(&status->fork[philo->r_fork]);
		printf_status(philo, "has taken a fork");
		pthread_mutex_lock(&status->fork[philo->l_fork]);
		printf_status(philo, "has taken a fork");
	}
	philo->now_time = get_time();
	printf_status(philo, "is eating");
	ft_usleep(status->tte);
	pthread_mutex_unlock(&status->fork[philo->l_fork]);
	pthread_mutex_unlock(&status->fork[philo->r_fork]);
	philo->eat_count++;
}

void	*c_die(void *phi)
{
	t_philo		*philo;
	t_status	*status;

	philo = (t_philo *)phi;
	status = philo->status;
	usleep(100);
	while (status->die == 0)
	{
		if ((get_time() - philo->now_time) > status->ttd && status->die == 0)
		{
			pthread_mutex_lock(&status->died);
			status->die = philo->id;
			usleep(2500);
			pthread_mutex_lock(&status->message);
			printf("%2lld ms %5d %2s\n", get_time() - status->start_time, \
														philo->id, "is died");
			pthread_mutex_unlock(&status->exit);
			return (NULL);
		}
		if ((status->must_eat <= philo->eat_count) && status->must_eat != -1)
			break ;
		usleep(100);
	}
	return (NULL);
}

void	*t_act(void *phi)
{
	t_philo		*philo;
	t_status	*status;

	philo = (t_philo *)phi;
	status = philo->status;
	philo->now_time = get_time();
	while (status->die == 0 && (status->must_eat > philo->eat_count || \
			status->must_eat == -1))
	{
		if (status->die == 0 && (status->must_eat > philo->eat_count || \
			status->must_eat == -1))
			eat_dinner(philo);
		if (status->die == 0 && (status->must_eat > philo->eat_count || \
			status->must_eat == -1))
			sleep_think(philo, status);
		if (status->die == 0 && (status->must_eat > philo->eat_count || \
			status->must_eat == -1))
			printf_status(philo, "is thinking");
	}
	return (NULL);
}	

void	*check_eat(void *sta)
{
	t_status	*status;
	int			i;
	int			count;

	status = (t_status *)sta;
	i = 0;
	while (status->die == 0)
	{	
		i = 0;
		count = 0;
		while (i < status->philo_num)
		{
			if (status->philo[i++].eat_count >= status->must_eat)
				count++;
		}
		if (status->philo_num == count)
		{
			pthread_mutex_lock(&status->message);
			printf("yammy~~\n");
			pthread_mutex_unlock(&status->exit);
			return (NULL);
		}
	}
	return (NULL);
}

int	create_tp(t_status *status)
{
	int			i;
	t_philo		*philo;

	i = -1;
	philo = status->philo;
	pthread_mutex_lock(&status->exit);
	status->start_time = get_time();
	while (++i < status->philo_num)
	{
		if (pthread_create(&philo[i].tid, NULL, t_act, (void *)&philo[i]) != 0)
			return (1);
		pthread_detach(philo[i].tid);
		if (pthread_create(&status->c_d, NULL, c_die, (void *)&philo[i]) != 0)
			return (1);
		pthread_detach(status->c_d);
		usleep(100);
	}
	if (status->must_eat != -1)
	{
		if (pthread_create(&status->ate, NULL, check_eat, (void *)status) != 0)
			return (1);
		pthread_detach(status->ate);
	}
	pthread_mutex_lock(&status->exit);
	return (0);
}
