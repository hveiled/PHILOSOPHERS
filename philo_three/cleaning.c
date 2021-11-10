/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hveiled <hveiled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 14:23:50 by hveiled           #+#    #+#             */
/*   Updated: 2021/05/22 18:47:24 by hveiled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"
#include <pthread.h>
#include <sys/semaphore.h>

void	cleaning(t_all *all)
{
	sem_close(all->fork);
	sem_close(all->chat);
	sem_unlink("/fork");
	sem_unlink("/chat");
}
