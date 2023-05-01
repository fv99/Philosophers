/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:30:03 by fvonsovs          #+#    #+#             */
/*   Updated: 2023/05/01 15:03:51 by fvonsovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philos(t_philo *philo, int n_philo)
{
	int	i;

	i = 0;
	while (i < n_philo)
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
	init_philos(data->philo, data->n_philo);
	return (0);
}

void	free_data(t_data *data)
{
	int	i;

	if (data)
	{
		if (data->philo)
		{
			i = 0;
			while (i < data->n_philo)
			{
				pthread_mutex_destroy(&data->philo[i].left);
				pthread_mutex_destroy(&data->philo[i].right);
				i++;
			}
			free(data->philo);
		}
	}
}

// test function
int test_init(t_data *data)
{
    int i;

    if (!data->philo)
        return (-1);
    for (i = 0; i < data->n_philo; i++)
    {
        printf("philo[%d]: id = %d, left = %p, right = %p\n", i, data->philo[i].id,
               &data->philo[i].left, &data->philo[i].right);

        if (pthread_mutex_trylock(&data->philo[i].left) != 0)
            return (-1);

        printf("philo[%d]: left mutex works\n", i);

        if (pthread_mutex_trylock(&data->philo[i].right) != 0)
        {
            pthread_mutex_unlock(&data->philo[i].left);
            return (-1);
        }

        printf("philo[%d]: right mutex works\n", i);

        pthread_mutex_unlock(&data->philo[i].left);
        pthread_mutex_unlock(&data->philo[i].right);
    }
    return (0);
}
