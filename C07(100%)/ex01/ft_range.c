/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabouayy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 09:31:10 by yabouayy          #+#    #+#             */
/*   Updated: 2026/07/31 09:42:04 by yabouayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*dest;
	int	len;
	int	i;

	i = 0;
	len = max - min;
	if (len <= 0)
		return (0);
	dest = malloc(len * sizeof(int));
	if (!dest)
		return (0);
	while (i < len)
	{
		dest[i] = min++;
		i++;
	}
	return (dest);
}
