/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hveiled <hveiled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 11:07:32 by hveiled           #+#    #+#             */
/*   Updated: 2021/05/22 15:42:03 by hveiled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"
#include <i386/types.h>
#include <pthread.h>
#include <sys/_types/_ssize_t.h>
#include <sys/_types/_timeval.h>
#include <sys/select.h>

void	lock_forks(t_philosopher *philo)
{
	philo->hungry = 1;
	pthread_mutex_lock(philo->fork_right);
	pthread_mutex_lock(&philo->chat);
	printf("%zd %d has taken a right fork\n", gettime()
		- philo->started, philo->id);
	pthread_mutex_unlock(&philo->chat);
	pthread_mutex_lock(philo->fork_left);
	pthread_mutex_lock(&philo->chat);
	printf("%zd %d has taken a left fork\n", gettime()
		- philo->started, philo->id);
	pthread_mutex_unlock(&philo->chat);
}

void	eating(t_philosopher *philo)
{
	if (philo->arg.must_eat > 0)
		philo->count_of_meals++;
	pthread_mutex_lock(&philo->chat);
	printf("%zd %d is eating\n", gettime() - philo->started, philo->id);
	pthread_mutex_unlock(&philo->chat);
	ft_usleep(philo->arg.time_to_eat);
	philo->last_meal = gettime();
	philo->hungry = 0;
}

void	sleeping(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->chat);
	printf("%zd %d is sleeping\n", gettime() - philo->started, philo->id);
	pthread_mutex_unlock(&philo->chat);
	ft_usleep(philo->arg.time_to_sleep);
}

void	thinkig(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->chat);
	printf("%zd %d is thinking\n", gettime() - philo->started, philo->id);
	pthread_mutex_unlock(&philo->chat);
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
		pthread_mutex_unlock(philo->fork_left);
		pthread_mutex_unlock(philo->fork_right);
		if (philo->count_of_meals == philo->arg.must_eat)
		{
			pthread_mutex_lock(philo->lock);
			break ;
		}
		sleeping(philo);
		thinkig(philo);
	}
	return (NULL);
}
