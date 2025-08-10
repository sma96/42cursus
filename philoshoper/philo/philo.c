/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sma <sma@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:59:12 by sma               #+#    #+#             */
/*   Updated: 2021/07/23 14:42:54 by sma              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_arg(char **argv)
{
	int			i;
	int			j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_status	status;

	if (argc > 6 || argc < 5)
	{
		write(1, "error\n", 6);
		return (0);
	}
	if (check_arg(argv))
	{
		write(1, "error\n", 6);
		return (0);
	}
	if (init_s(&status, argv))
	{
		write(1, "error\n", 6);
		return (0);
	}
	create_tp(&status);
	destroy_mutex_free(&status);
	return (0);
}
