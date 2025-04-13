/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_in_one.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguney <iguney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:48:38 by iguney            #+#    #+#             */
/*   Updated: 2025/04/13 07:52:55 by iguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

char	*all_in_one(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	j = 0;
	i = 0;
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 2) * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[i] != '\0')
		str[j++] = s1[i++];
	str[j++] = ' ';
	i = 0;
	while (s2[i] != '\0')
		str[j++] = s2[i++];
	str[j] = '\0';
	return (str);
}
