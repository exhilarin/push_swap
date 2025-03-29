/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_message.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas-guney <ilyas-guney@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 06:38:46 by iguney            #+#    #+#             */
/*   Updated: 2025/03/29 16:07:26 by ilyas-guney      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	message(char *string)
{
	if (!ft_strncmp(string, "rrr", 3))
		ft_printf("rrr");
	else if (!ft_strncmp(string, "rra", 3))
		ft_printf("rra");
	else if (!ft_strncmp(string, "rrb", 3))
		ft_printf("rrb");
	else if (!ft_strncmp(string, "rr", 2))
		ft_printf("rr");
	else if (!ft_strncmp(string, "ss", 2))
		ft_printf("ss");
	else if (!ft_strncmp(string, "sa", 2))
		ft_printf("sa");
	else if (!ft_strncmp(string, "sb", 2))
		ft_printf("sb");
	else if (!ft_strncmp(string, "pa", 2))
		ft_printf("pa");
	else if (!ft_strncmp(string, "pb", 2))
		ft_printf("pb");
	else if (!ft_strncmp(string, "ra", 2))
		ft_printf("ra");
	else if (!ft_strncmp(string, "rb", 2))
		ft_printf("rb");
    ft_printf("\n");
}

