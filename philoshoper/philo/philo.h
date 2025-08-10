/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sma <sma@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 13:58:48 by sma               #+#    #+#             */
/*   Updated: 2021/07/23 14:38:30 by sma              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <unistd.h>

struct	s_status;

typedef struct s_philo{
	int					id;
	int					l_fork;
	int					r_fork;
	long long			now_time;
	int					eat_count;
	pthread_t			tid;
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
	pthread_mutex_t		*fork;
	pthread_mutex_t		message;
	pthread_mutex_t		died;
	pthread_mutex_t		exit;
	pthread_t			ate;
	pthread_t			c_d;
	t_philo				*philo;
}				t_status;

int			ft_atoi(const char *c);
int			ft_isdigit(int c);
int			init_s(t_status *status, char **argv);
int			init_mutex(t_status *status);
int			init_philo(t_status *status);
int			create_tp(t_status *status);
void		*thread_act(void *phi);
void		printf_status(t_philo *philo, char *str);
long long	get_time(void);
void		ft_usleep(int time);
void		all_free(t_status *status);
void	destroy_mutex_free(t_status *status);
void		destroy_mutex_all(t_status *status);
void		sleep_think(t_philo *philo, t_status *status);

#endif
