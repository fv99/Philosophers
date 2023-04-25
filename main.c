/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:56:52 by fvonsovs          #+#    #+#             */
/*   Updated: 2023/04/25 17:21:04 by fvonsovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philosopher(int *num)
{
	while (1)
	{
		think(num);
		pickup(num);
		eat(num);
		putdown(num);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 5 || argc != 6)
		you_fucked_up("Usage: ./philo number_of_philosophers time_to_die time_to_eat \
						time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
	else
	{
		// initialize our philosophers
		// prolly need a struct to hold our arguments


	}
	return(0);
}