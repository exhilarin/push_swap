/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas-guney <ilyas-guney@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 03:11:38 by iguney            #+#    #+#             */
/*   Updated: 2025/03/30 01:29:49 by ilyas-guney      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_a(t_stack **stack_a, int flag)
{
	int		tmp;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return ;
	tmp = (*stack_a)->data;
	del_one_from_stack(stack_a, tmp);
	add_back_to_stack(stack_a, tmp);
	if (!flag)
		message("ra");
	}

void	rotate_b(t_stack **stack_b, int flag)
{
	int		tmp;

	if (!stack_b || !(*stack_b) || !(*stack_b)->next)
		return ;
	tmp = (*stack_b)->data;
	del_one_from_stack(stack_b, tmp);
	add_back_to_stack(stack_b, tmp);
	if (!flag)
		message("rb");
}

void	rotate_rotate(t_stack **stack_a, t_stack **stack_b)
{
	rotate_a(stack_a, 1);
	rotate_b(stack_b, 1); 
	message("rr");
}
