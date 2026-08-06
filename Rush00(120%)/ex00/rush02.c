/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohel-fi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 10:27:26 by mohel-fi          #+#    #+#             */
/*   Updated: 2026/07/19 17:29:12 by yabouayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	print_line(int i, int x, char c, char s);

void	rush(int x, int y)
{
	int	i;
	int	j;

	if (x <= 0 || y <= 0)
		return ;
	i = 0;
	j = 0;
	while (j < y)
	{
		if (j == 0)
			print_line(i, x, 'A', 'B');
		else if (y > 2 && j < y - 1)
			print_line(i, x, 'B', ' ');
		else if (j == y - 1)
			print_line(i, x, 'C', 'B');
		ft_putchar('\n');
		i = 0;
		j++;
	}
}

void	print_line(int i, int x, char c, char s)
{
	ft_putchar(c);
	if (x > 2)
	{
		while (i < x - 2)
		{
			ft_putchar(s);
			i++;
		}
	}
	if (x > 1)
		ft_putchar(c);
}
