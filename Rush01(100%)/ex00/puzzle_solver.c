/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puzzle_solver.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymezian <aymezian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 17:58:20 by aymezian          #+#    #+#             */
/*   Updated: 2026/07/26 17:58:21 by aymezian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_adjacent_cell(int grid[4][4], int gap, int num);
int	check_arguments(int argc, char **argv);
int	check_cell(int grid[4][4], int gap, int pattern[16]);

int	puzzle_solver(int grid[4][4], int pattern[16], int gap)
{
	int	num;

	if (gap == 16)
		return (1);
	num = 0;
	while (++num <= 4)
	{
		if (check_adjacent_cell(grid, gap, num) == 0)
		{
			grid[gap / 4][gap % 4] = num;
			if (check_cell(grid, gap, pattern) == 0)
			{
				if (puzzle_solver(grid, pattern, gap + 1) == 1)
					return (1);
			}
			grid[gap / 4][gap % 4] = 0;
		}
	}
	return (0);
}
