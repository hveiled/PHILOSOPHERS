/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hveiled <hveiled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 19:11:20 by hveiled           #+#    #+#             */
/*   Updated: 2021/05/22 17:26:27 by hveiled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"
#include <sys/_types/_ssize_t.h>
#include <sys/semaphore.h>

int	dead(t_philosopher **philo, int i)
{
	ssize_t	time;

	time = gettime();
	if ((*philo)->arg.time_to_die < time - philo[i]->last_meal \
	&& philo[i]->hungry)
	{
		sem_wait(philo[i]->chat);
		printf("%zd %d is DEAD\n", time - philo[i]->started, philo[i]->id);
		exit (2);
	}
	return (0);
}

void	*check_if(void *arg)
{
	int				i;
	t_philosopher	**philo;

	philo = (t_philosopher **)arg;
	while (1)
	{
		i = -1;
		while (++i < (*philo)->arg.nmbr_of_philosophers)
		{
			if (philo[i]->count_of_meals == philo[i]->arg.must_eat)
				exit(1);
			if (dead(philo, i))
				exit(2);
		}
	}
	return (NULL);
}
