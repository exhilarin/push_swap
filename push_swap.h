#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <stdlib.h>

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
void	take_argv(t_stack **stack_a, char *av[]);
void	add_to_stack(t_stack **stack, int data);
t_stack	*new_node(int data);


#endif

