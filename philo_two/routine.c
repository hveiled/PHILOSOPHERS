/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hveiled <hveiled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 11:07:32 by hveiled           #+#    #+#             */
/*   Updated: 2021/05/22 16:06:52 by hveiled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"
#include <i386/types.h>
#include <pthread.h>
#include <sys/_types/_ssize_t.h>
#include <sys/_types/_timeval.h>
#include <sys/select.h>
#include <sys/semaphore.h>

void	lock_forks(t_philosopher *philo)
{
	philo->hungry = 1;
	sem_wait(philo->fork);
	sem_wait(philo->chat);
	printf("%zd %d has taken a left fork\n", gettime()
		- philo->started, philo->id);
	sem_post(philo->chat);
	sem_wait(philo->fork);
	sem_wait(philo->chat);
	printf("%zd %d has taken a right fork\n", gettime()
		- philo->started, philo->id);
	sem_post(philo->chat);
}

void	eating(t_philosopher *philo)
{
	if (philo->arg.must_eat > 0)
		philo->count_of_meals++;
	sem_wait(philo->chat);
	printf("%zd %d is eating\n", gettime() - philo->started, philo->id);
	sem_post(philo->chat);
	ft_usleep(philo->arg.time_to_eat);
	philo->last_meal = gettime();
	philo->hungry = 0;
}

void	sleeping(t_philosopher *philo)
{
	sem_wait(philo->chat);
	printf("%zd %d is sleeping\n", gettime() - philo->started, philo->id);
	sem_post(philo->chat);
	ft_usleep(philo->arg.time_to_sleep);
}

void	thinkig(t_philosopher *philo)
{
	sem_wait(philo->chat);
	printf("%zd %d is thinking\n", gettime() - philo->started, philo->id);
	sem_post(philo->chat);
}

void	*routine(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	philo->count_of_meals = 0;
	philo->last_meal = gettime();
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (1)
	{
		lock_forks(philo);
		eating(philo);
		sem_post(philo->fork);
		sem_post(philo->fork);
		if (philo->count_of_meals == philo->arg.must_eat)
			break ;
		sleeping(philo);
		thinkig(philo);
	}
	return (NULL);
}
