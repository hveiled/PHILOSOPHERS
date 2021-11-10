/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hveiled <hveiled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 19:30:01 by hveiled           #+#    #+#             */
/*   Updated: 2021/05/20 14:40:15 by hveiled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int	error_check(int ac, char *av[])
{
	int	i;
	int	j;

	i = 0;
	if (ac < 5 || ac > 6)
		return (ft_error("Invalid number of arguments"));
	if (av[1][0] == '-' || av[1][0] == '0')
		exit(ft_error("Invalid number of philosofers"));
	while (++i < ac)
	{
		j = -1;
		while (av[i][++j] != '\0')
			if (av[i][j] < '0' || av[i][j] > '9')
				return (ft_error("Numeric arguments required"));
	}
	return (0);
}

int	mallocate(t_all *all, int i)
{
	all->philo = (t_philosopher **)malloc(sizeof(t_philosopher *)
			* all->arg.nmbr_of_philosophers);
	i = -1;
	while (++i < all->arg.nmbr_of_philosophers)
	{
		all->philo[i] = malloc(sizeof(t_philosopher));
		if (!all->philo[i])
			return (0);
	}
	all->thread = malloc(sizeof(pthread_t) * all->arg.nmbr_of_philosophers);
	if (!all->philo || !all->thread)
		return (0);
	return (1);
}

int	pars_line(t_all *all, int ac, char *av[], int i)
{
	if (error_check(ac, av))
		return (0);
	all->arg.nmbr_of_philosophers = ft_atoi(av[1]);
	all->arg.time_to_die = ft_atoi(av[2]);
	all->arg.time_to_eat = ft_atoi(av[3]);
	all->arg.time_to_sleep = ft_atoi(av[4]);
	if (!mallocate(all, i))
		return (0);
	if (av[5])
		all->arg.must_eat = ft_atoi(av[5]);
	else
		all->arg.must_eat = -1;
	return (1);
}
