/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabouayy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 11:13:43 by yabouayy          #+#    #+#             */
/*   Updated: 2026/07/19 17:33:39 by yabouayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	i;
	int	j;

	if (x <= 0 || y <= 0)
		return ;
	j = 0;
	while (j < y)
	{
		i = 0;
		while (i < x)
		{
			if (i == 0 && (j == 0 || j == y - 1))
				ft_putchar('A');
			else if (i == x - 1 && (j == 0 || j == y - 1))
				ft_putchar('C');
			else if (i == 0 || i == x - 1 || j == 0 || j == y - 1)
				ft_putchar('B');
			else
				ft_putchar(' ');
			i++;
		}
		ft_putchar('\n');
		j++;
	}
}
