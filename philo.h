/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:57:56 by fvonsovs          #+#    #+#             */
/*   Updated: 2023/04/25 17:18:01 by fvonsovs         ###   ########.fr       */
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
	int					left;
	int					right;
	pthread_mutex_t*	mutex;
}	t_philo;

// philo.c

int	you_fucked_up(char *msg);


#endif