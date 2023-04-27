/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvonsovs <fvonsovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:33:00 by fvonsovs          #+#    #+#             */
/*   Updated: 2023/04/27 16:40:20 by fvonsovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_number(char *argv)
{
	int	i;

	i = 0;
	if (((argv[i] == '+') || (argv[i] == '-')) && argv[i + 1] != '\0')
		i++;
	while (argv[i] && ft_isdigit(argv[i]))
		i++;
	if (argv[i] != '\0' && !ft_isdigit(argv[i]))
		return (0);
	return (1);
}

int	is_zero(char *argv)
{
	int	i;

	i = 0;
	if ((argv[i] == '+') || (argv[i] == '-'))
		i++;
	while (argv[i] && argv[i] == '0')
		i++;
	if (argv[i] != '\0')
		return (0);
	return (1);
}

// need to check for MAX/MIN_INT
long	ft_atol(const char *s)
{
	int		i;
	long	res;
	long	coeff;

	i = 0;
	res = 0;
	coeff = 1;
	while (s[i] && (s[i] == ' '))
		i++;
	if (!s[i])
		return (0);
	if (s[i] == '+')
		i++;
	else if (s[i] == '-')
	{
		coeff = -1;
		i++;
	}
	while (s[i] && ft_isdigit(s[i]))
	{
		res = res * 10 + s[i] - '0';
		i++;
	}
	return (res * coeff);
}

int	check_input(char **argv)
{
	int		i;
	int		zeros;
	long	num;

	zeros = 0;
	i = 1;
	while (argv[i])
	{
		if (!is_number(argv[i]))
			you_fucked_up("Non-digits in input");
		num = ft_atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			you_fucked_up("Integer out of range");
		zeros += is_zero(argv[i]);
		i++;
	}
	if (zeros > 0)
		you_fucked_up("Zeros in input");
	return (1);
}
