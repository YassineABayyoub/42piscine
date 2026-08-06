/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabouayy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 12:22:36 by yabouayy          #+#    #+#             */
/*   Updated: 2026/07/31 12:22:47 by yabouayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_total_len(int size, char **strs, char *sep)
{
	int	i;
	int	total;

	i = 0;
	total = 0;
	while (i < size)
		total += ft_strlen(strs[i++]);
	total += (size - 1) * ft_strlen(sep);
	return (total + 1);
}

int	ft_check_size(int size, char **result)
{
	if (size != 0)
		return (0);
	*result = malloc(1);
	if (!(*result))
		return (1);
	(*result)[0] = '\0';
	return (1);
}

void	ft_copy(char *result, int size, char **strs, char *sep)
{
	int	i;
	int	j;
	int	r;

	i = 0;
	r = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			result[r++] = strs[i][j++];
		if (i != size - 1)
		{
			j = 0;
			while (sep[j])
				result[r++] = sep[j++];
		}
		i++;
	}
	result[r] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;

	if (ft_check_size(size, &result))
		return (result);
	result = malloc(ft_total_len(size, strs, sep));
	if (!result)
		return (0);
	ft_copy(result, size, strs, sep);
	return (result);
}
