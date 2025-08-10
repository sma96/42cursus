/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sma <sma@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 14:00:08 by sma               #+#    #+#             */
/*   Updated: 2021/07/23 19:34:10 by sma              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	all_free_unlink(t_status *status)
{
	int	i;

	i = 0;
	while (i < status->philo_num)
	{
		kill(status->pid[i++], SIGTERM);
		sem_post(status->must_e);
	}
	free(status->philo);
	free(status->pid);
	sem_close(status->fork);
	sem_close(status->message);
	sem_close(status->died);
	sem_close(status->must_e);
	sem_close(status->death);
	sem_unlink("fork");
	sem_unlink("message");
	sem_unlink("died");
	sem_unlink("must_e");
	sem_unlink("death");
}

void	sleep_think(t_philo *philo, t_status *status)
{
	printf_status(philo, get_time(), "is sleeping");
	usleep(status->tts);
}

void	ft_usleep(int time)
{
	long long	start;

	start = get_time();
	while (get_time() < (start + time))
		usleep(100);
}

void	*check_flag(void *sta)
{
	t_status	*status;

	status = (t_status *)sta;
	sem_wait(status->died);
	status->die = 1;
	return (NULL);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
