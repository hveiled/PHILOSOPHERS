/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hveiled <hveiled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 14:23:50 by hveiled           #+#    #+#             */
/*   Updated: 2021/05/22 21:22:55 by hveiled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"
#include <pthread.h>
#include <sys/semaphore.h>

void	cleaning(t_all *all)
{
	sem_unlink("/fork");
	sem_unlink("/chat");
	sem_close(all->fork);
	sem_close(all->chat);
}
