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

void	error(void);
long	ft_atol(const char *str);
int		check_argv(char *av[]);
int		check_zero(const char *str);

#endif

