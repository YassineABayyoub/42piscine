/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymezian <aymezian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 17:56:23 by aymezian          #+#    #+#             */
/*   Updated: 2026/07/26 17:56:26 by aymezian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_row_left(int grid[4][4], int gap, int pattern[16])
{
	int	col;
	int	tallest;
	int	count;

	if (gap % 4 != 3)
		return (0);
	col = 0;
	tallest = grid[gap / 4][col];
	count = 1;
	col++;
	while (col <= 3)
	{
		if (grid[gap / 4][col] > tallest)
		{
			tallest = grid[gap / 4][col];
			count++;
		}
		col++;
	}
	return (count != pattern[8 + gap / 4]);
}

int	check_row_right(int grid[4][4], int gap, int pattern[16])
{
	int	col;
	int	tallest;
	int	count;

	if (gap % 4 != 3)
		return (0);
	col = 3;
	tallest = grid[gap / 4][col];
	count = 1;
	col--;
	while (col >= 0)
	{
		if (grid[gap / 4][col] > tallest)
		{
			tallest = grid[gap / 4][col];
			count++;
		}
		col--;
	}
	return (count != pattern[12 + gap / 4]);
}

int	check_col_up(int grid[4][4], int gap, int pattern[16])
{
	int	row;
	int	tallest;
	int	count;

	if (gap / 4 != 3)
		return (0);
	row = 0;
	tallest = grid[row][gap % 4];
	count = 1;
	row++;
	while (row <= 3)
	{
		if (grid[row][gap % 4] > tallest)
		{
			tallest = grid[row][gap % 4];
			count++;
		}
		row++;
	}
	return (count != pattern[gap % 4]);
}

int	check_col_down(int grid[4][4], int gap, int pattern[16])
{
	int	row;
	int	tallest;
	int	count;

	if (gap / 4 != 3)
		return (0);
	row = 3;
	tallest = grid[row][gap % 4];
	count = 1;
	row--;
	while (row >= 0)
	{
		if (grid[row][gap % 4] > tallest)
		{
			tallest = grid[row][gap % 4];
			count++;
		}
		row--;
	}
	return (count != pattern[4 + gap % 4]);
}

int	check_cell(int grid[4][4], int gap, int pattern[16])
{
	if (gap % 4 == 3)
	{
		if (check_row_left(grid, gap, pattern) == 1)
			return (1);
		if (check_row_right(grid, gap, pattern) == 1)
			return (1);
	}
	if (gap / 4 == 3)
	{
		if (check_col_up(grid, gap, pattern) == 1)
			return (1);
		if (check_col_down(grid, gap, pattern) == 1)
			return (1);
	}
	return (0);
}
