/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_message.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguney <iguney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 06:38:46 by iguney            #+#    #+#             */
/*   Updated: 2025/04/13 07:52:55 by iguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

void	message(char *string)
{
	if (!ft_strncmp(string, "rrr", 3))
		ft_printf("rrr\n");
	else if (!ft_strncmp(string, "rra", 3))
		ft_printf("rra\n");
	else if (!ft_strncmp(string, "rrb", 3))
		ft_printf("rrb\n");
	else if (!ft_strncmp(string, "rr", 2))
		ft_printf("rr\n");
	else if (!ft_strncmp(string, "ss", 2))
		ft_printf("ss\n");
	else if (!ft_strncmp(string, "sa", 2))
		ft_printf("sa\n");
	else if (!ft_strncmp(string, "sb", 2))
		ft_printf("sb\n");
	else if (!ft_strncmp(string, "pa", 2))
		ft_printf("pa\n");
	else if (!ft_strncmp(string, "pb", 2))
		ft_printf("pb\n");
	else if (!ft_strncmp(string, "ra", 2))
		ft_printf("ra\n");
	else if (!ft_strncmp(string, "rb", 2))
		ft_printf("rb\n");
}
