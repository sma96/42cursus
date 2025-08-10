/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sma <sma@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 16:24:00 by sma               #+#    #+#             */
/*   Updated: 2021/07/23 20:07:06 by sma              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	init_philo(t_status *status)
{
	int		i;

	i = 0;
	status->philo = (t_philo *)malloc(sizeof(t_philo) * status->philo_num);
	if (!(status->philo))
		return (1);
	while (i < status->philo_num)
	{
		status->philo[i].eat_count = 0;
		status->philo[i].id = i + 1;
		status->philo[i].status = status;
		i++;
	}
	return (0);
}

int	init_sem(t_status *status)
{
	sem_unlink("fork");
	status->fork = sem_open("fork", O_CREAT, 0644, status->philo_num);
	if (status->fork == SEM_FAILED)
		return (1);
	sem_unlink("message");
	status->message = sem_open("message", O_CREAT, 0644, 1);
	if (status->message == SEM_FAILED)
		return (1);
	sem_unlink("died");
	status->died = sem_open("died", O_CREAT, 0644, 0);
	if (status->died == SEM_FAILED)
		return (1);
	sem_unlink("must_e");
	status->must_e = sem_open("must_e", O_CREAT, 0644, 0);
	if (status->must_e == SEM_FAILED)
		return (1);
	sem_unlink("death");
	status->death = sem_open("death", O_CREAT, 0644, 1);
	if (status->death == SEM_FAILED)
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
	if (init_sem(status))
		return (1);
	if (init_philo(status))
		return (1);
	status->pid = (pid_t *)malloc(sizeof(pid_t) * status->philo_num);
	if (status->pid == 0)
		return (1);
	return (0);
}
