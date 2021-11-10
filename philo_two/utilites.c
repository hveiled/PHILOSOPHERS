/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilites.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hveiled <hveiled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 20:17:35 by hveiled           #+#    #+#             */
/*   Updated: 2021/05/20 12:16:26 by hveiled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		res;
	int		r;

	i = 0;
	res = 0;
	r = 0;
	while (str[i] == '\t' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == '\n' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i++] - '0');
		r++;
	}
	return (res);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_usleep(int time_to)
{
	ssize_t			time;
	struct timeval	timeval;

	gettimeofday(&timeval, NULL);
	time = timeval.tv_sec * 1000 + timeval.tv_usec / 1000;
	while ((timeval.tv_sec * 1000 + timeval.tv_usec / 1000) - time < time_to)
	{
		gettimeofday(&timeval, NULL);
		usleep(100);
	}
}
