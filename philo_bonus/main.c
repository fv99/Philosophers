/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:56:52 by fvonsovs          #+#    #+#             */
/*   Updated: 2023/05/11 16:19:41 by fvonsovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 5 || argc == 6)
	{
		check_input(argv);
		init_data(&data, argv);
		free_data(&data);
	}
	else
		you_fucked_up("Usage: ./philo_bonus number_of_philosophers\
			time_to_die time_to_eat time_to_sleep \
			[number_of_times_each_philosopher_must_eat]\n");
	return (0);
}
