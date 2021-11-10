/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hveiled <hveiled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 10:33:42 by hveiled           #+#    #+#             */
/*   Updated: 2021/05/20 11:50:29 by hveiled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int	ft_error(char *error_message)
{
	write(1, error_message, ft_strlen(error_message));
	write(1, "\n", 1);
	exit(1);
}
