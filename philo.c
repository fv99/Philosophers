/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:28:13 by fvonsovs          #+#    #+#             */
/*   Updated: 2023/05/01 14:59:32 by fvonsovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// error handling
int	you_fucked_up(char *msg)
{
	printf("\tERROR: %s\n", msg);
	exit(1);
}

unsigned long long timestamp(void)
{
	struct timeval	time;
	gettimeofday(&time, NULL);
	return(time.tv_sec * 1000 + time.tv_usec / 1000);
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
		printf("%llu %i has taken a fork", time, num);
	else if (mode == 1)
		printf("%llu %i is eating", time, num);
	else if (mode == 2)
		printf("%llu %i is sleeping", time, num);
	else if (mode == 3)
		printf("%llu %i is thinking", time, num);
	else if (mode == 4)
		printf("%llu %i died", time, num);
}
