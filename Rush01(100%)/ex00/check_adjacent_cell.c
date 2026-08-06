/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_adjacent_cell.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymezian <aymezian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 17:55:56 by aymezian          #+#    #+#             */
/*   Updated: 2026/07/26 17:56:00 by aymezian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_adjacent_cell(int grid[4][4], int gap, int num)
{
	int	i;
	int	j;

	if (num == 0)
		return (1);
	i = 0;
	while (i < 4)
	{
		if (grid[gap / 4][i] == num)
			return (1);
		i++;
	}
	j = 0;
	while (j < 4)
	{
		if (grid[j][gap % 4] == num)
			return (1);
		j++;
	}
	return (0);
}
