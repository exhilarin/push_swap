/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iguney <iguney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:09:46 by iguney            #+#    #+#             */
/*   Updated: 2025/04/13 07:52:55 by iguney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*src;

	i = 0;
	j = 0;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if ((len > ft_strlen(s + start)))
		len = ft_strlen(s + start);
	src = malloc(sizeof(char) * (len + 1));
	if (!src)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
		{
			src[j] = s[i];
			j++;
		}
		i++;
	}
	src[j] = '\0';
	return (src);
}
