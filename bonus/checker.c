/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguney <iguney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 00:35:00 by yenyilma          #+#    #+#             */
/*   Updated: 2025/04/13 04:52:02 by iguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

static void	execute_action(char *action, t_stack *a, t_stack *b)
{
	if (ft_strncmp(action, "sa\n", 3) == 0)
		swap_a(a);
	else if (ft_strncmp(action, "sb\n", 3) == 0)
		swap_b(b);
	else if (ft_strncmp(action, "ss\n", 3) == 0)
		swap_swap(a, b);
	else if (ft_strncmp(action, "rra\n", 4) == 0)
		rev_rotate_a(a);
	else if (ft_strncmp(action, "rrb\n", 4) == 0)
		rev_rotate_b(b);
	else if (ft_strncmp(action, "rrr\n", 4) == 0)
		rev_rotate_rotate(a, b);
	else if (ft_strncmp(action, "pa\n", 3) == 0)
		push_a(b, a);
	else if (ft_strncmp(action, "pb\n", 3) == 0)
		push_b(a, b);
	else if (ft_strncmp(action, "ra\n", 3) == 0)
		rotate_a(a);
	else if (ft_strncmp(action, "rb\n", 3) == 0)
		rotate_b(b);
	else if (ft_strncmp(action, "rr\n", 3) == 0)
		rotate_rotate(a, b);
	else
		error_exit();
}

static void	read_actions(t_stack *a, t_stack *b)
{
	char	*line;

	line = get_next_line(0);
	while (line != NULL)
	{
		execute_action(line, a, b);
		free(line);
		line = get_next_line(0);
	}
	free(line);
}

static void	space_error(char **str)
{
	int	flag;
	int	i;
	int	j;

	flag = 0;
	i = 1;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] >= '0' && str[i][j] <= '9')
			{
				flag = 1;
				break ;
			}
			j++;
		}
		if (flag == 0)
			error_exit();
		flag = 0;
		i++;
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac < 2)
		return (0);
	stack_a = ft_stacknew();
	stack_b = ft_stacknew();
	if (parse(stack_a, ac, av) || !stack_a || !stack_b)
		error_exit();
	space_error(av);
	read_actions(stack_a, stack_b);
	if (is_sorted_a(stack_a) && stack_b->count == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_stackclear(stack_a, free);
	ft_stackclear(stack_b, free);
	return (0);
}