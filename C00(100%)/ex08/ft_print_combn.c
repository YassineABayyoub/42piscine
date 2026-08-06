/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabouayy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 20:34:33 by yabouayy          #+#    #+#             */
/*   Updated: 2026/07/29 21:05:09 by yabouayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_comb(int *tab, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar(tab[i] + '0');
		i++;
	}
	if (tab[0] != 10 - n)
		write(1, ", ", 2);
}

void	ft_print_combn(int n)
{
	int	tab[10];
	int	i;

	if (n <= 0 || n >= 10)
		return ;
	i = 0;
	while (i < n)
	{
		tab[i] = i;
		i++;
	}
	while (1)
	{
		print_comb(tab, n);
		i = n - 1;
		while (i >= 0 && tab[i] == 10 - n + i)
			i--;
		if (i < 0)
			break ;
		tab[i]++;
		while (++i < n)
			tab[i] = tab[i - 1] + 1;
	}
}
