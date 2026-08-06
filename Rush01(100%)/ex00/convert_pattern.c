/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_pattern.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymezian <aymezian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 17:57:44 by aymezian          #+#    #+#             */
/*   Updated: 2026/07/26 17:57:46 by aymezian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*convert_pattern(char *str)
{
	int	*pattern;
	int	i;
	int	j;

	pattern = malloc(sizeof(int) * 16);
	if (!pattern)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != ' ')
		{
			pattern[j] = str[i] - '0';
			j++;
		}
		i++;
	}
	return (pattern);
}
