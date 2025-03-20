/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas-guney <ilyas-guney@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 02:29:03 by iguney            #+#    #+#             */
/*   Updated: 2025/03/20 01:56:22 by ilyas-guney      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	int	    i;
	int     sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int	check_zero(const char *str)
{
	int	i;
	int len;
	int check;

	i = 0;
	check = 0;
	len = ft_strlen(str);
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '0')
			check++;
		i++;
	}
	if (check == len)
		return (1);
	return (0);
}

int error(void)
{
	ft_printf("Error!");
	return (0);
}