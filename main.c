/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:56:52 by fvonsovs          #+#    #+#             */
/*   Updated: 2023/04/27 16:42:06 by fvonsovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 5 || argc != 6)
		you_fucked_up("Usage: ./philo number_of_philosophers time_to_die time_to_eat \
						time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
	else
	{
		check_input(argv);
		init_data(data, argv);


	}
	return(0);
}