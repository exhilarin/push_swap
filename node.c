/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguney <iguney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 18:52:50 by ilyas-guney       #+#    #+#             */
/*   Updated: 2025/04/12 22:57:57 by iguney           ###   ########.fr       */
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

void free_stack(t_stack *stack)
{
    t_stack *tmp;

    while (stack)
    {
        tmp = stack;
        stack = stack->next;
        free(tmp);
    }
    free(stack);
}