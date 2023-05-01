/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:57:56 by fvonsovs          #+#    #+#             */
/*   Updated: 2023/05/01 15:02:43 by fvonsovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>

// structs go here
typedef struct s_philo
{
	int					id;
	pthread_mutex_t		left;
	pthread_mutex_t		right;
	pthread_t			thread;
}	t_philo;

typedef struct s_data
{
	t_philo	*philo;
	int		n_philo;
	int		t_die;
	int		t_eat;
	int		t_sleep;
	int		n_eat;
}	t_data;

// philo.c

int		you_fucked_up(char *msg);

// libft_utils.c

int		ft_isdigit(int str);

int		ft_atoi(char *str);

// philo_utils.c

int		init_philos(t_philo *philo, int n_philo);

int		init_data(t_data *data, char **argv);

void	free_data(t_data *data);

int 	test_init(t_data *data);

// input_check.c

int		is_number(char *argv);

int		is_zero(char *argv);

int		check_input(char **argv);

#endif