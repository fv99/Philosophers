/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:57:56 by fvonsovs          #+#    #+#             */
/*   Updated: 2023/04/25 14:00:33 by fvonsovs         ###   ########.fr       */
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
typedef struct s_stack
{
	int				num;
	int				index;
	struct s_stack	*next;
}	t_stack;

#endif