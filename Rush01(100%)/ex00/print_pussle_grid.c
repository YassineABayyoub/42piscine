/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pussle_grid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymezian <aymezian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 17:58:06 by aymezian          #+#    #+#             */
/*   Updated: 2026/07/26 17:58:08 by aymezian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_puzzle_grid(int grid[4][4])
{
	int	j;
	int	i;

	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			ft_putchar(grid[j][i] + 48);
			if (i != 3)
				write(1, " ", 1);
			i++;
		}
		write(1, "\n", 1);
		j++;
	}
}

/* TEST MAIN - COMMENTED OUT FOR PRODUCTION BUILD
#include <stdio.h>

int main(void)
{
	int normal[4][4] = {{1,2,3,4},{2,3,4,1},{3,4,1,2},{4,1,2,3}};
	int zeros[4][4] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};

	write(1, "Normal:\n", 8);
	print_puzzle_grid(normal);
	write(1, "\nZeros:\n", 8);
	print_puzzle_grid(zeros);
	return (0);
}
*/
