/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabouayy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 16:57:04 by yabouayy          #+#    #+#             */
/*   Updated: 2026/08/01 16:57:07 by yabouayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			ft_char_index(char c, char *base);
long long	ft_parse_nbr(char *nbr, char *base_from, int *error);
char		*ft_itoa_base(long long value, char *base_to);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_is_whitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	ft_is_valid_base(char *base)
{
	int	i;
	int	len;

	if (!base || ft_strlen(base) < 2)
		return (0);
	len = ft_strlen(base);
	i = 0;
	while (i < len)
	{
		if (base[i] == '+' || base[i] == '-' || ft_is_whitespace(base[i])
			|| ft_char_index(base[i], base) != i)
			return (0);
		i++;
	}
	return (1);
}

int	ft_skip_prefix(char *nbr, int *i)
{
	int	sign;

	while (ft_is_whitespace(nbr[*i]))
		(*i)++;
	sign = 1;
	while (nbr[*i] == '+' || nbr[*i] == '-')
	{
		if (nbr[*i] == '-')
			sign = -sign;
		(*i)++;
	}
	return (sign);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int			error;
	long long	value;

	if (!nbr || !ft_is_valid_base(base_from) || !ft_is_valid_base(base_to))
		return (NULL);
	error = 0;
	value = ft_parse_nbr(nbr, base_from, &error);
	if (error)
		return (NULL);
	return (ft_itoa_base(value, base_to));
}
