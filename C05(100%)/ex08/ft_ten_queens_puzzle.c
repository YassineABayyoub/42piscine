/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabouayy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 10:53:37 by yabouayy          #+#    #+#             */
/*   Updated: 2026/07/30 11:25:13 by yabouayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_solution(int pos[10])
{
	int	i;

	i = 0;
	while (i < 10)
	{
		ft_putchar(pos[i] + '0');
		i++;
	}
	ft_putchar('\n');
}

int	is_valid(int pos[10], int col, int row)
{
	int	i;
	int	diff;

	i = 0;
	while (i < col)
	{
		if (pos[i] == row)
			return (0);
		diff = pos[i] - row;
		if (diff < 0)
			diff = -diff;
		if (diff == col - i)
			return (0);
		i++;
	}
	return (1);
}

void	solve(int pos[10], int col, int *count)
{
	int	row;

	if (col == 10)
	{
		print_solution(pos);
		(*count)++;
		return ;
	}
	row = 0;
	while (row < 10)
	{
		if (is_valid(pos, col, row))
		{
			pos[col] = row;
			solve(pos, col + 1, count);
		}
		row++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	pos[10];
	int	count;

	count = 0;
	solve(pos, 0, &count);
	return (count);
}
