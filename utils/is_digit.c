/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_digit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguney <iguney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:07:00 by ilyas-guney       #+#    #+#             */
/*   Updated: 2025/04/13 03:48:17 by iguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	is_digit(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if ((str[i] > '9' || str[i] < '0') && (str[i] != '-' && str[i] != '+'))
			return (0);
		if (((ft_strlen(str)) == 1) && (str[i] == '-' || str[i] == '+'))
			return (0);
	}
	return (1);
}
