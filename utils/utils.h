/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguney <iguney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 11:42:02 by iguney            #+#    #+#             */
/*   Updated: 2025/03/24 06:53:31 by iguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../ft_printf/ft_printf.h"
# include "../push_swap.h"
# include <stdlib.h>
# include <unistd.h>

unsigned int	ft_strlen(const char *str);
long			ft_atol(const char *str);
char			*all_in_one(char const *s1, char const *s2);
char			**seperate_str(char const *s, char c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strdup(const char *s1);
int             ft_strncmp(char *s1, char *s2, size_t n);
int				check_zero(const char *str);
int             is_digit(char *str);
int				error(void);
void            message(char *string);

#endif