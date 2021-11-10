/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hveiled <hveiled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 10:33:42 by hveiled           #+#    #+#             */
/*   Updated: 2021/05/21 10:45:58 by hveiled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int	ft_error(char *error_message)
{
	write(1, error_message, ft_strlen(error_message));
	write(1, "\n", 1);
	exit(1);
}
