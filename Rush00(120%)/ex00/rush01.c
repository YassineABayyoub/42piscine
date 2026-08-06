/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mtao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 14:51:16 by ael-mtao          #+#    #+#             */
/*   Updated: 2026/07/19 20:30:31 by mohel-fi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_char(int i, int j, int x, int y)
{
	if ((j == 0 && i == 0) || (j == y - 1 && i == x - 1 && x > 1 && y > 1))
		ft_putchar('/');
	else if ((j == 0 && i == x - 1) || (j == y - 1 && i == 0))
		ft_putchar('\\');
	else if (j == 0 || j == y - 1)
		ft_putchar('*');
	else if (i == 0 || i == x - 1)
		ft_putchar('*');
	else
		ft_putchar(' ');
}

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
			print_char(i, j, x, y);
			i++;
		}
		ft_putchar('\n');
		j++;
	}
}
