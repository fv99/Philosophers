/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:28:13 by fvonsovs          #+#    #+#             */
/*   Updated: 2023/05/02 14:56:10 by fvonsovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	// if (philo->id % 2 == 0)
	// 	ft_usleep(philo->data->t_eat);
	while(1)
	{
		philo_fork(philo);
		philo_eat(philo);
		print_status(2, philo->id);
		ft_usleep(philo->data->t_sleep);
		print_status(3, philo->id);
	}
}

void	philo_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->left);
	print_status(0, philo->id);
	pthread_mutex_lock(&philo->right);
	print_status(0, philo->id);
}

void	philo_eat(t_philo *philo)
{
	print_status(1, philo->id);
	philo->n_ate++;
	philo->last_ate = timestamp();
	pthread_mutex_unlock(&philo->right);
	pthread_mutex_unlock(&philo->left);

}

/* 
	mode 0 - timestamp_in_ms [num] has taken a fork
	mode 1 - timestamp_in_ms [num] is eating
	mode 2 - timestamp_in_ms [num] is sleeping
	mode 3 - timestamp_in_ms [num] is thinking
	mode 4 - timestamp_in_ms [num] died
 */
void	print_status(int mode, int num)
{
	unsigned long long	time;

	time = timestamp();
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
