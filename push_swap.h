#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "utils/utils.h"
# include "ft_printf/ft_printf.h"
# include <stdlib.h>
# include <stdio.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_stack
{
	int				data;
	int				cost;
	int				total_cost;
	int				size;
	int				index;
	struct s_stack	*next;
} t_stack;

void	take_argv(t_stack **stack_a, char *av[]);
char	**seperate_argv(char *av[]);
int		check_argv(char **splitted);

t_stack	*new_node(int data);
void	add_back_to_stack(t_stack **stack, int data);
void	add_front_to_stack(t_stack **stack, int data);
void	del_one_from_stack(t_stack **stack, int data);
void	print_stack(t_stack *stack);

int		check_zero(const char *str);
int		stack_size(t_stack *stack);
void	free_stack(t_stack *stack);
int		is_sorted(t_stack *stack);

void	algorithm(t_stack **stack_a, t_stack **stack_b);
void	sort_for_three(t_stack *stack_a);
t_stack	*find_best_match(t_stack *stack_a, t_stack *stack_b);
t_stack *find_target_in_a(t_stack *stack_a, int data);
t_stack	*find_target_in_b(t_stack *stack_b, int value);
int	calculate_total_cost(t_stack *node_a, t_stack *stack_a,
	t_stack *node_b, t_stack *stack_b);
int	calculate_cost(t_stack *node, t_stack *stack);
void	move_to_top(t_stack **stack_a, t_stack **stack_b, t_stack *best_match, t_stack *target_b);
int	get_index(t_stack *node, t_stack *stack);


void	swap_a(t_stack *stack_a);
void	swap_b(t_stack *stack_b);
void	swap_swap(t_stack *stack_a, t_stack *stack_b);
void	push_a(t_stack **stack_a, t_stack **stack_b);
void	push_b(t_stack **stack_a, t_stack **stack_b);
void	rotate_a(t_stack **stack_a);
void	rotate_b(t_stack **stack_b);
void	rotate_rotate(t_stack **stack_a, t_stack **stack_b);
void	rev_rotate_a(t_stack **stack_a);
void	rev_rotate_b(t_stack **stack_b);
void	rev_rotate_rotate(t_stack **stack_a, t_stack **stack_b);

#endif

