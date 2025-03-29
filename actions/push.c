/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas-guney <ilyas-guney@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 05:58:53 by iguney            #+#    #+#             */
/*   Updated: 2025/03/30 00:43:32 by ilyas-guney      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    push_a(t_stack **stack_a, t_stack **stack_b)
{
    if (!stack_b || !*stack_b)
        return ;

    message("pa");
    add_front_to_stack(stack_a, (*stack_b)->data);
    del_one_from_stack(stack_b, (*stack_b)->data);
}

void    push_b(t_stack **stack_a, t_stack **stack_b)
{
    if (!stack_a || !*stack_a)
        return ;
        
    message("pb");
    add_front_to_stack(stack_b, (*stack_a)->data);
    del_one_from_stack(stack_a, (*stack_a)->data);
}
