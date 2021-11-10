/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem_initialisation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hveiled <hveiled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 14:17:15 by hveiled           #+#    #+#             */
/*   Updated: 2021/05/21 15:47:14 by hveiled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"
#include <pthread.h>
#include <sys/_pthread/_pthread_mutex_t.h>
#include <sys/semaphore.h>

int	mtx_initialisation(t_all *all)
{
	int	i;

	i = -1;
	sem_unlink("/fork");
	sem_unlink("/chat");
	all->fork = sem_open("/fork", O_CREAT, 0666, \
	all->arg.nmbr_of_philosophers);
	all->chat = sem_open("/chat", O_CREAT, 0666, 1);
	if (all->fork == SEM_FAILED || all->chat == SEM_FAILED)
		return (0);
	while (++i < all->arg.nmbr_of_philosophers)
	{
		all->philo[i]->fork = all->fork;
		all->philo[i]->chat = all->chat;
	}
	return (1);
}
