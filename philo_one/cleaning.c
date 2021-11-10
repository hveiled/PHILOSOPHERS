/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hveiled <hveiled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 14:23:50 by hveiled           #+#    #+#             */
/*   Updated: 2021/05/21 13:50:54 by hveiled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"
#include <pthread.h>

void	cleaning(t_all *all)
{
	int	i;

	i = -1;
	while (++i < all->arg.nmbr_of_philosophers)
		pthread_mutex_destroy(all->mtx[i]);
	i = -1;
	while (++i < all->arg.nmbr_of_philosophers)
	{
		free(all->mtx[i]);
		free(all->philo[i]);
	}
	free(all->mtx);
	free(all->philo);
	free(all->thread);
}
