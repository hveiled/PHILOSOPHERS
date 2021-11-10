/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philosofer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hveiled <hveiled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 10:04:13 by hveiled           #+#    #+#             */
/*   Updated: 2021/05/20 14:42:19 by hveiled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int	create_philosofer(t_all *all, int i)
{
	all->philo[i]->id = i + 1;
	all->philo[i]->arg = all->arg;
	all->philo[i]->started = gettime();
	all->philo[i]->thread = &all->thread[i];
	return (1);
}
