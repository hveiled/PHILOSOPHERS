/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hveiled <hveiled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 10:14:30 by hveiled           #+#    #+#             */
/*   Updated: 2021/05/20 10:38:57 by hveiled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TWO_H
# define PHILO_TWO_H

# include <pthread.h>
# include <semaphore.h>
# include <sys/_types/_ssize_t.h>
# include <sys/_types/_time_t.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <sys/_types/_timeval.h>

typedef struct s_time
{
	int		nmbr_of_philosophers;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		must_eat;
}t_time;

typedef struct s_philosopher
{
	int				id;
	int				i;
	char			status;
	ssize_t			last_meal;
	ssize_t			started;
	sem_t			*fork;
	sem_t			*chat;
	char			need;
	int				args[6];
	pthread_t		*thread;
	t_time			arg;
	int				count_of_meals;
	int				hungry;
}t_philosopher;

typedef struct s_all
{
	t_time			arg;
	t_philosopher	**philo;
	pthread_t		*thread;
	sem_t			*fork;
	sem_t			*chat;
}t_all;

int		pars_line(t_all *all, int ac, char *av[], int i);
void	cleaning(t_all *all);
int		mtx_initialisation(t_all *all);
int		ft_error(char *error_message);
int		ft_strlen(char *str);
int		ft_atoi(const char *str);
void	*routine(void *arg);
void	ft_usleep(int time_to);
void	*check_if(void *arg);
ssize_t	gettime(void);
int		create_philosofer(t_all *all, int i);

#endif // !PHILOSOFERS_H
