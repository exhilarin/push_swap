#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <stdlib.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_stack
{
	int    			data;
	struct s_stack	*next;
	struct s_stack	*pre;
} t_stack;

int		error(void);
long	ft_atol(const char *str);
int		check_argv(char *av[]);
int		check_zero(const char *str);
void	print_stack(t_stack *stack);
void	take_argv(t_stack **stack_a, t_stack **stack_b, char *av[]);
void	add_to_stack(t_stack **stack, int data);
void	swap_a(t_stack *stack_a);
t_stack	*new_node(int data);


#endif

