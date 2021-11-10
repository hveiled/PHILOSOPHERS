/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_initialisation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hveiled <hveiled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 14:17:15 by hveiled           #+#    #+#             */
/*   Updated: 2021/05/21 16:17:05 by hveiled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"
#include <pthread.h>
#include <sys/_pthread/_pthread_mutex_t.h>

int	mtx_initialisation(t_all *all)
{
	int	i;

	i = -1;
	while (++i < all->arg.nmbr_of_philosophers)
		if (pthread_mutex_init(all->mtx[i], NULL) != 0)
			return (0);
	if (pthread_mutex_init(&all->lock, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&all->chat, NULL) != 0)
		return (0);
	return (1);
}
