/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabouayy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 09:42:41 by yabouayy          #+#    #+#             */
/*   Updated: 2026/08/01 16:29:35 by yabouayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	len;
	int	i;

	i = 0;
	len = max - min;
	if (len <= 0)
	{
		*range = 0;
		return (0);
	}
	*range = malloc(len * sizeof(int));
	if (!(*range))
		return (-1);
	while (i < len)
	{
		(*range)[i] = min++;
		i++;
	}
	return (len);
}
