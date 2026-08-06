/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabouayy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 16:58:37 by yabouayy          #+#    #+#             */
/*   Updated: 2026/08/01 16:58:41 by yabouayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>

int	ft_strlen(char *str);
int	ft_skip_prefix(char *nbr, int *i);

int	ft_char_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

static int	ft_accumulate_digit(long long *res, int idx, long long base_len,
				int sign)
{
	if (*res > (LLONG_MAX - idx) / base_len)
		return (1);
	*res = *res * base_len + idx;
	if (sign == 1 && *res > INT_MAX)
		return (1);
	if (sign == -1 && *res > (long long)INT_MAX + 1)
		return (1);
	return (0);
}

long long	ft_parse_nbr(char *nbr, char *base_from, int *error)
{
	long long	result;
	long long	base_len;
	int			sign;
	int			idx;
	int			i;

	i = 0;
	sign = ft_skip_prefix(nbr, &i);
	base_len = ft_strlen(base_from);
	result = 0;
	while (nbr[i])
	{
		idx = ft_char_index(nbr[i], base_from);
		if (idx == -1)
			break ;
		if (ft_accumulate_digit(&result, idx, base_len, sign))
		{
			*error = 1;
			break ;
		}
		i++;
	}
	return (result * sign);
}

static int	ft_fill_buffer(long long n, char *buf, char *base_to)
{
	int	base_len;
	int	i;

	base_len = ft_strlen(base_to);
	i = 0;
	if (n == 0)
		buf[i++] = base_to[0];
	while (n > 0)
	{
		buf[i++] = base_to[n % base_len];
		n /= base_len;
	}
	return (i);
}

char	*ft_itoa_base(long long value, char *base_to)
{
	char		buf[70];
	char		*res;
	long long	n;
	int			len;
	int			i;

	n = value;
	if (n < 0)
		n = -n;
	len = ft_fill_buffer(n, buf, base_to);
	res = (char *)malloc(sizeof(char) * (len + (value < 0) + 1));
	if (!res)
		return (NULL);
	i = 0;
	if (value < 0)
		res[i++] = '-';
	while (len > 0)
		res[i++] = buf[--len];
	res[i] = '\0';
	return (res);
}
