/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabouayy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 19:29:02 by yabouayy          #+#    #+#             */
/*   Updated: 2026/07/29 20:30:18 by yabouayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int	num0;
	int	num1;

	num0 = 0;
	while (num0 <= 98)
	{
		num1 = num0 + 1;
		while (num1 <= 99)
		{
			ft_putchar((num0) / 10 + '0');
			ft_putchar((num0) % 10 + '0');
			write(1, " ", 1);
			ft_putchar((num1) / 10 + '0');
			ft_putchar((num1) % 10 + '0');
			if (!(num0 == 98 && num1 == 99))
				write(1, ", ", 2);
			num1++;
		}
		num0++;
	}
}
