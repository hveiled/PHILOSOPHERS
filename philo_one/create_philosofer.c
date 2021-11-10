/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philosofer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hveiled <hveiled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 10:04:13 by hveiled           #+#    #+#             */
/*   Updated: 2021/05/20 11:50:31 by hveiled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int	create_philosofer(t_all *all, int i)
{
	all->philo[i]->id = i + 1;
	all->philo[i]->arg = all->arg;
	all->philo[i]->started = gettime();
	all->philo[i]->fork_right = all->mtx[i];
	all->philo[i]->thread = &all->thread[i];
	all->philo[i]->lock = &all->lock;
	if (i == all->arg.nmbr_of_philosophers - 1)
		all->philo[i]->fork_left = all->mtx[0];
	else
		all->philo[i]->fork_left = all->mtx[i + 1];
	return (1);
}
