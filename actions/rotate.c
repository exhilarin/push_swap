/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas-guney <ilyas-guney@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 03:11:38 by iguney            #+#    #+#             */
/*   Updated: 2025/03/29 01:26:59 by ilyas-guney      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_a(t_stack **stack_a)
{
	int		tmp;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return ;
	tmp = (*stack_a)->data;
	del_one_from_stack(stack_a, tmp);  // Başındaki elemanı kaldır
	add_back_to_stack(stack_a, tmp);  // En son eleman olarak ekle
	message("ra");
	if (is_sorted(*stack_a) && (*stack_a)->size == stack_size(*stack_a))
		return ;
}

void	rotate_b(t_stack **stack_b)
{
	int		tmp;

	if (!stack_b || !(*stack_b) || !(*stack_b)->next)
		return ;
	tmp = (*stack_b)->data;
	del_one_from_stack(stack_b, tmp);  // Başındaki elemanı kaldır
	add_back_to_stack(stack_b, tmp);  // En son eleman olarak ekle
	message("rb");
}

void	rotate_rotate(t_stack **stack_a, t_stack **stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
	message("rr");
}
