/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sma <sma@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 13:58:48 by sma               #+#    #+#             */
/*   Updated: 2021/07/20 16:57:34 by sma              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <unistd.h>
# include <semaphore.h>
# include <signal.h>

struct	s_status;

typedef struct s_philo{
	int					id;
	long long			now_time;
	int					eat_count;
	struct s_status		*status;
}				t_philo;

typedef struct s_status{
	int					philo_num;
	int					ttd;
	int					tte;
	int					tts;
	int					must_eat;
	int					die;
	long long			start_time;
	sem_t				*fork;
	sem_t				*message;
	sem_t				*died;
	sem_t				*must_e;
	sem_t				*death;
	pid_t				*pid;
	pthread_t			check_e;
	pthread_t			death_flag;
	t_philo				*philo;
}				t_status;

int			ft_atoi(const char *c);
int			ft_isdigit(int c);
int			init_s(t_status *status, char **argv);
int			create_tp(t_status *status);
void		process_act(t_status *status, t_philo *philo);
void		printf_status(t_philo *philo, long long time, char *str);
long long	get_time(void);
void		ft_usleep(int time);
void		all_free_unlink(t_status *status);
void		sleep_think(t_philo *philo, t_status *status);
void		*check_flag(void *sta);
char		*ft_itoa(int n);
int			ft_strlen(char *str);

#endif
