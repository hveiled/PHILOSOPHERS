/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hveiled <hveiled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 10:12:45 by hveiled           #+#    #+#             */
/*   Updated: 2021/05/22 21:23:49 by hveiled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"
#include <pthread.h>
#include <stdio.h>
#include <sys/_pthread/_pthread_mutex_t.h>
#include <sys/fcntl.h>
#include <sys/semaphore.h>

int	main(int ac, char *av[])
{
	int				i;
	t_all			all;
	pthread_t		waiter_thread;

	i = -1;
	if (!pars_line(&all, ac, av, 0) || !mtx_initialisation(&all))
		return (1);
	while (++i < all.arg.nmbr_of_philosophers)
		create_philosofer(&all, i);
	pthread_create(&waiter_thread, NULL, check_if, (void *)all.philo);
	i = -1;
	while (++i < all.arg.nmbr_of_philosophers)
	{
		if (pthread_create(&all.thread[i], NULL, routine, (void *)all.philo[i]))
			return (1);
		pthread_detach(all.thread[i]);
	}
	pthread_join(waiter_thread, NULL);
	return (0);
}
