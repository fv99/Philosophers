/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:57:56 by fvonsovs          #+#    #+#             */
/*   Updated: 2023/05/15 16:51:48 by fvonsovs         ###   ########.fr       */
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
# include <semaphore.h>
# include <fcntl.h>
# include <sys/stat.h> 
# include <sys/types.h>
# include <sys/wait.h> 

// structs go here
typedef struct s_philo
{
	pid_t			pid;
	int				id;
	long			last_ate;
	int				n_ate;
	int				dead;
	int				immortal;
	pthread_t		thread;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	t_philo	*philo;
	int		n_philo;
	int		t_die;
	int		t_eat;
	int		t_sleep;
	int		n_eat;
	int		running;
	sem_t	*sem_print;
	sem_t	*forks;
	sem_t	*sem_eating;
}	t_data;

// philo_bonus.c

void		philo_routine(void *arg);

void		philo_fork(t_philo *philo);

void		philo_eat(t_philo *philo);

void		*is_dead(void *arg);

void		print_status(t_philo *philo, int mode, int num);

// libft_utils.c

int			you_fucked_up(char *msg);

int			ft_isdigit(int str);

int			ft_atoi(char *str);

// philo_utils.c

int			init_philos(t_data *data);

int			init_data(t_data *data, char **argv);

int			free_data(t_data *data);

long long	timestamp(void);

void		ft_usleep(int ms);

// int 	test_init(t_data *data);

// input_check.c

int			is_number(char *argv);

int			is_zero(char *argv);

int			check_input(char **argv);

#endif