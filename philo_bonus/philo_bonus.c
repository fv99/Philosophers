/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:28:13 by fvonsovs          #+#    #+#             */
/*   Updated: 2023/05/15 16:53:18 by fvonsovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	philo_routine(void *arg)
{
	t_philo		*philo;
	pthread_t	thread;

	philo = (t_philo *)arg;
	pthread_create(&thread, NULL, is_dead, philo);
	if (philo->id % 2 == 0)
		ft_usleep(philo->data->t_eat / 2);
	while (philo->dead == 0 && philo->data->running == 1)
	{
		philo_fork(philo);
		philo_eat(philo);
		if (philo->n_ate >= philo->data->n_eat)
		{
			philo->immortal = 1;
			break ;
		}
	}
	pthread_join(thread, NULL);
}

void	philo_fork(t_philo *philo)
{
	if (philo->data->n_philo == 1 || !philo->data->running)
	{
		ft_usleep(philo->data->t_die + 1);
		return ;
	}
	if (philo->data->running)
	{
		sem_wait(philo->data->forks);
		print_status(philo, 0, philo->id);
		sem_wait(philo->data->forks);
		print_status(philo, 0, philo->id);
	}
}

void	philo_eat(t_philo *philo)
{
    sem_wait(philo->data->sem_eating);
    print_status(philo, 1, philo->id);
    philo->n_ate++;
    philo->last_ate = timestamp();
    sem_post(philo->data->sem_eating);
	if (philo->n_ate >= philo->data->n_eat)
	{
		sem_post(philo->data->forks);
		sem_post(philo->data->forks);
		philo->immortal = 1;
		return ;
	}
	ft_usleep(philo->data->t_eat);
	sem_post(philo->data->forks);
	sem_post(philo->data->forks);
	print_status(philo, 2, philo->id);
	ft_usleep(philo->data->t_sleep);
	print_status(philo, 3, philo->id);
}

void	*is_dead(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (philo->dead == 0 && !philo->immortal)
	{
		sem_wait(philo->data->sem_eating);
		if (timestamp() - philo->last_ate >= philo->data->t_die)
		{
			print_status(philo, 4, philo->id);
			sem_wait(philo->data->sem_print);
			philo->dead = 1;
			philo->data->running = 0;
			sem_post(philo->data->forks);
			sem_post(philo->data->forks);
			sem_post(philo->data->sem_eating);
		}
		sem_post(philo->data->sem_eating);
		ft_usleep(5);
	}
	sem_post(philo->data->sem_print);
	return (NULL);
}

/*
	mode 0 - timestamp_in_ms [num] has taken a fork
	mode 1 - timestamp_in_ms [num] is eating
	mode 2 - timestamp_in_ms [num] is sleeping
	mode 3 - timestamp_in_ms [num] is thinking
	mode 4 - timestamp_in_ms [num] died
*/
void	print_status(t_philo *philo, int mode, int num)
{
	unsigned long long	time;

	time = timestamp();
	sem_wait(philo->data->sem_print);
	if (philo->data->running == 1)
	{
		if (mode == 0)
			printf("%llu %i has taken a fork\n", time, num);
		else if (mode == 1)
			printf("%llu %i is eating\n", time, num);
		else if (mode == 2)
			printf("%llu %i is sleeping\n", time, num);
		else if (mode == 3)
			printf("%llu %i is thinking\n", time, num);
		else if (mode == 4)
			printf("%llu %i has died. Press F to pay respects.\n", time, num);
	}
	sem_post(philo->data->sem_print);
}
