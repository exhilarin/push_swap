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
	int    			data;
	struct s_stack	*next;
	struct s_stack	*pre;
} t_stack;

t_stack	*new_node(int data);
long	ft_atol(const char *str);
void	take_argv(t_stack **stack_a, char *av[]);
void	print_stack(t_stack *stack);
void	add_to_stack(t_stack **stack, int data);
void	swap_a(t_stack *stack_a);
void	free_stack(t_stack *stack);
int		check_argv(char **splitted);
int		check_zero(const char *str);
int		check_zero(const char *str);
char	*all_in_one(char const *s1, char const *s2);
char	**seperate_argv(char *av[]);


#endif

