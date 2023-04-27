/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:30:03 by fvonsovs          #+#    #+#             */
/*   Updated: 2023/04/27 17:07:09 by fvonsovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philos(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	philo = malloc(sizeof(t_philo) * data->n_philo);
	if (!philo)
		you_fucked_up("Allocation failed in init_philos");
	while (i < data->n_philo)
	{
		philo[i].id = i + 1;
		pthread_mutex_init(&philo[i].left, NULL);
		pthread_mutex_init(&philo[i].right, NULL);
		i++;
	}
	return (0);
}

int	init_data(t_data *data, char **argv)
{
	data->n_philo = ft_atoi(argv[1]);
	data->t_die = ft_atoi(argv[2]);
	data->t_eat = ft_atoi(argv[3]);
	data->t_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->n_eat = ft_atoi(argv[5]);
	data->philo = malloc(sizeof(t_philo) * data->n_philo);
	if (!data->philo)
		you_fucked_up("Allocation failed");
	init_philos(data->philo, data);
	return (0);
}

