/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_all_spaces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguney <iguney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 01:10:35 by iguney            #+#    #+#             */
/*   Updated: 2025/04/13 02:30:12 by iguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	is_all_spaces(const char *str)
{
	while (*str)
	{
		if (!is_space(*str))
			return (0);
		str++;
	}
	return (1);
}
