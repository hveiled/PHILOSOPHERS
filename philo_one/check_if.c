/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hveiled <hveiled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 19:11:20 by hveiled           #+#    #+#             */
/*   Updated: 2021/05/22 20:30:18 by hveiled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int	dead(t_philosopher **philo, int i, int *someone_is_dead)
{
	ssize_t	time;

	time = gettime();
	if ((time - philo[i]->last_meal > philo[i]->arg.time_to_die) \
	&& philo[i]->hungry)
	{
		pthread_mutex_lock(&philo[i]->chat);
		printf("%zd %d is DEAD\n", time - philo[i]->started,
			philo[i]->id);
		*someone_is_dead = 1;
		return (1);
	}
	return (0);
}

int	full(t_philosopher **philo, int i, int *full)
{
	if (philo[i]->count_of_meals == philo[i]->arg.must_eat)
	{
		*full = 1;
		return (1);
	}
	return (0);
}

void	*check_if(void *arg)
{
	int				i;
	t_philosopher	**philo;
	int				full_or_dead;

	full_or_dead = 0;
	philo = (t_philosopher **)arg;
	while (!full_or_dead)
	{
		i = -1;
		while (++i < (*philo)->arg.nmbr_of_philosophers)
		{
			if (full(philo, i, &full_or_dead))
				break ;
			if (dead(philo, i, &full_or_dead))
				break ;
		}
	}
	return (NULL);
}
