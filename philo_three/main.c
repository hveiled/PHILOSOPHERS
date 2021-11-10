/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hveiled <hveiled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 10:12:45 by hveiled           #+#    #+#             */
/*   Updated: 2021/05/22 18:54:45 by hveiled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"
#include <pthread.h>
#include <sys/semaphore.h>

void	process_creation(t_all *all, int i)
{
	pthread_t		waiter_thread;

	if (pthread_create(&all->thread[i], NULL, routine, (void *)all->philo[i]))
		ft_error("pthread error");
	pthread_detach(all->thread[i]);
	if (pthread_create(&waiter_thread, NULL, check_if, (void *)all->philo))
		ft_error("pthread error");
	pthread_join(waiter_thread, NULL);
}

void	wait_kill(t_all *all, int *status, int i)
{
	waitpid(-1, status, 0);
	*status = WEXITSTATUS(*status);
	if (status != 0)
	{
		i = -1;
		while (++i < all->arg.nmbr_of_philosophers)
			kill(all->pid[i], SIGKILL);
	}
	else
		exit(0);
}

int	main(int ac, char *av[])
{
	int				i;
	t_all			all;
	int				status;

	i = -1;
	status = 0;
	if (!pars_line(&all, ac, av, 0) || !mtx_initialisation(&all))
		return (1);
	while (++i < all.arg.nmbr_of_philosophers)
		create_philosofer(&all, i);
	i = -1;
	while (++i < all.arg.nmbr_of_philosophers)
	{
		all.pid[i] = fork();
		if (all.pid[i] == -1)
			ft_error("fork error");
		else if (all.pid[i] == 0)
			process_creation(&all, i);
	}
	wait_kill(&all, &status, i);
	cleaning(&all);
	return (0);
}
