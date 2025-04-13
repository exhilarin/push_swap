/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguney <iguney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 00:35:00 by yenyilma          #+#    #+#             */
/*   Updated: 2025/04/13 08:08:11 by iguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap_bonus.h"
#include "./get_next_line/get_next_line.h"

static	void exit_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

static void	execute_action(char *action, t_stack *a, t_stack *b)
{
	if (ft_strncmp(action, "sa\n", 3) == 0)
		swap_a(&a, 0);
	else if (ft_strncmp(action, "sb\n", 3) == 0)
		swap_b(&b, 0);
	else if (ft_strncmp(action, "ss\n", 3) == 0)
		swap_swap(&a, &b);
	else if (ft_strncmp(action, "rra\n", 4) == 0)
		rev_rotate_a(&a, 0);
	else if (ft_strncmp(action, "rrb\n", 4) == 0)
		rev_rotate_b(&b, 0);
	else if (ft_strncmp(action, "rrr\n", 4) == 0)
		rev_rotate_rotate(&a, &b);
	else if (ft_strncmp(action, "pa\n", 3) == 0)
		push_a(&b, &a);
	else if (ft_strncmp(action, "pb\n", 3) == 0)
		push_b(&a, &b);
	else if (ft_strncmp(action, "ra\n", 3) == 0)
		rotate_a(&a, 0);
	else if (ft_strncmp(action, "rb\n", 3) == 0)
		rotate_b(&b, 0);
	else if (ft_strncmp(action, "rr\n", 3) == 0)
		rotate_rotate(&a, &b);
	else
		exit_error();
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

static void	error_space(char **str)
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
			exit_error();
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
	stack_a = NULL;
	stack_b = NULL;
	if (take_argv(&stack_a, av) || !stack_a || !stack_b)
		exit_error();
	error_space(av);
	read_actions(stack_a, stack_b);
	if (is_sorted_a(stack_a) && stack_size(stack_b) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
