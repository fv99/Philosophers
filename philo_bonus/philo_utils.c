/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:30:03 by fvonsovs          #+#    #+#             */
/*   Updated: 2023/05/11 16:41:29 by fvonsovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	init_philos(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->n_philo)
	{
		data->philo[i].id = i + 1;
		data->philo[i].last_ate = timestamp();
		data->philo[i].n_ate = 0;
		data->philo[i].data = data;
		data->philo[i].dead = 0;
		data->philo[i].immortal = 0;
		data->philo[i].pid = fork();
		if (data->philo[i].pid < 0)
			you_fucked_up("Couldnt fork process");
		else if (data->philo[i].pid == 0)
		{
			philo_routine(&data->philo[i]);
			exit(0);
		}
	}
	i = -1;
	while (++i < data->n_philo)
		waitpid(data->philo[i].pid, NULL, 0);
	return (free_data(data));
}

int	init_data(t_data *data, char **argv)
{
	sem_init(&data->sem_eating, 0, 1);
	sem_init(&data->sem_print, 0, 1);
	if (sem_init(&data->forks, 0, data->n_philo) != 0)
		you_fucked_up("Couldnt init forks");
	data->running = 1;
	data->n_philo = ft_atoi(argv[1]);
	data->t_die = ft_atoi(argv[2]);
	data->t_eat = ft_atoi(argv[3]);
	data->t_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->n_eat = ft_atoi(argv[5]);
	else if (!argv[5])
		data->n_eat = INT_MAX - 1;
	data->philo = malloc(sizeof(t_philo) * data->n_philo);
	if (!data->philo)
		you_fucked_up("Allocation failed");
	init_philos(data);
	return (0);
}

long long	timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	ft_usleep(int ms)
{
	long int	time;

	time = timestamp();
	while (timestamp() - time < ms)
		usleep(ms / 10);
}

int	free_data(t_data *data)
{
	if (data)
	{
		if (data->philo)
		{
			sem_destroy(&data->forks);
			free(data->philo);
			sem_destroy(&data->sem_eating);
			sem_destroy(&data->sem_print);
		}
	}
	return (0);
}

/* // test function
int test_init(t_data *data)
{
    int i;

    if (!data->philo)
        return (-1);
    for (i = 0; i < data-		free_data(&data);>n_philo; i++)
    {
        printf("philo[%d]: id = %d, left \
		= %p, right = %p\n", i, data->philo[i].id,
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
 */