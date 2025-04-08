/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas-guney <ilyas-guney@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 18:52:50 by ilyas-guney       #+#    #+#             */
/*   Updated: 2025/03/30 02:37:44 by ilyas-guney      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *new_node(int data)
{
    t_stack *node;

    node = malloc(sizeof(t_stack));
    if (!node)
        return (NULL);
    node->data = data;
    node->next = NULL;
    return (node);
}

void add_back_to_stack(t_stack **stack, int data) 
{
    t_stack *new;
    t_stack *tmp;

    new = new_node(data);
    if (!new)
        return;

    if (*stack == NULL)
        *stack = new;
    else {
        tmp = *stack;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new;
    }
}


void add_front_to_stack(t_stack **stack, int data)
{
    t_stack *new;

    if (!stack)
        return;
    new = new_node(data);
    if (!new)
        return;
    new->next = *stack;
    *stack = new;
}

void del_one_from_stack(t_stack **stack, int data)
{
    if (!stack || !*stack)
        return;

    t_stack *tmp = *stack;
    t_stack *prev = NULL;

    while (tmp)
    {
        if (tmp->data == data)
        {
            if (prev)
                prev->next = tmp->next;
            else
                *stack = tmp->next;
            free(tmp);
            return;
        }
        prev = tmp;
        tmp = tmp->next;
    }
}

void print_stack(t_stack *stack) 
{
    while (stack) 
    {
        ft_printf("[%d]", stack->data);
        if (stack->next)
            ft_printf(" -> ");
        stack = stack->next;
    }
    ft_printf("\n");
}

void compare_first_last(t_stack **stack_a)
{
    int size;
    int mid;
    int index;

    size = stack_size(*stack_a);
    mid = size / 2;
    index = get_index(*stack_a, (*stack_a));
    if (index < mid)
        rotate_a(stack_a, 0);
    else
        rev_rotate_a(stack_a, 0);
}