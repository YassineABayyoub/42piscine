/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymezian <aymezian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 17:57:54 by aymezian          #+#    #+#             */
/*   Updated: 2026/07/26 17:57:56 by aymezian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c);
int		ft_strlen(char *str);
int		check_arguments(int argc, char **argv);
int		*convert_pattern(char *str);
int		check_adjacent_cell(int grid[4][4], int gap, int num);
int		check_row_left(int grid[4][4], int gap, int pattern[16]);
int		check_row_right(int grid[4][4], int gap, int pattern[16]);
int		check_col_up(int grid[4][4], int gap, int pattern[16]);
int		check_col_down(int grid[4][4], int gap, int pattern[16]);
int		check_cell(int grid[4][4], int gap, int pattern[16]);
int		puzzle_solver(int grid[4][4], int pattern[16], int gap);
void	print_puzzle_grid(int grid[4][4]);

void	init_grid(int grid[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		*pattern;
	int		grid[4][4];

	if (check_arguments(argc, argv) == 0)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	pattern = convert_pattern(argv[1]);
	if (pattern == NULL)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	init_grid(grid);
	if (puzzle_solver(grid, pattern, 0) == 1)
		print_puzzle_grid(grid);
	else
	{
		free(pattern);
		write(1, "Error\n", 6);
		return (1);
	}
	free(pattern);
	return (0);
}

/* ================================================================= */
/*  TEST MAIN - COMMENTED OUT FOR PRODUCTION BUILD                    */
/*  Uncomment the main below and comment out the main above to test   */
/* ================================================================= */

/*
#include <stdio.h>

void putstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

int	main(void)
{
	int		*pattern;
	int		grid[4][4];
	int		i;
	int		j;
	int		result;
	int		passed;
	int		total;

	passed = 0;
	total = 0;

	// TEST 1: check_arguments valid
	total++;
	result = check_arguments(2,
		(char *[3]){"./rush01", "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2", NULL});
	if (result == 1)
		passed++;
	write(1, result ? "[OK] " : "[KO] ", 5);
	putstr("test check_arguments valid\n");

	// TEST 2: check_arguments empty string
	total++;
	result = check_arguments(2,
		(char *[3]){"./rush01", "", NULL});
	if (result == 0)
		passed++;
	write(1, !result ? "[OK] " : "[KO] ", 5);
	putstr("test check_arguments empty\n");

	// TEST 3: check_arguments no args
	total++;
	result = check_arguments(1,
		(char *[2]){"./rush01", NULL});
	if (result == 0)
		passed++;
	write(1, !result ? "[OK] " : "[KO] ", 5);
	putstr("test check_arguments no args\n");

	// TEST 4: check_arguments too many args
	total++;
	result = check_arguments(3,
		(char *[4]){"./rush01", "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2", "extra", NULL});
	if (result == 0)
		passed++;
	write(1, !result ? "[OK] " : "[KO] ", 5);
	putstr("test check_arguments too many args\n");

	// TEST 5: check_arguments bad digit
	total++;
	result = check_arguments(2,
		(char *[3]){"./rush01", "5 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2", NULL});
	if (result == 0)
		passed++;
	write(1, !result ? "[OK] " : "[KO] ", 5);
	putstr("test check_arguments bad digit\n");

	// TEST 6: ft_strlen
	total++;
	result = ft_strlen("4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2");
	if (result == 31)
		passed++;
	write(1, (result == 31) ? "[OK] " : "[KO] ", 5);
	putstr("test ft_strlen\n");

	// TEST 7: convert_pattern
	total++;
	pattern = convert_pattern("4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2");
	result = 1;
	if (pattern == NULL)
		result = 0;
	else
	{
		i = 0;
		while (i < 16)
		{
			if (pattern[i] != "4321122243211222"[i] - '0')
				result = 0;
			i++;
		}
	}
	if (result == 1)
		passed++;
	write(1, result ? "[OK] " : "[KO] ", 5);
	putstr("test convert_pattern\n");
	free(pattern);

	// TEST 8: full solve valid pattern
	total++;
	pattern = convert_pattern("4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2");
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
	result = puzzle_solver(grid, pattern, 0);
	if (result == 1)
		passed++;
	write(1, result ? "[OK] " : "[KO] ", 5);
	putstr("test full solve\n");
	if (result == 1)
		print_puzzle_grid(grid);
	free(pattern);

	// TEST 9: full solve no solution
	total++;
	pattern = convert_pattern("1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1");
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
	result = puzzle_solver(grid, pattern, 0);
	if (result == 0)
		passed++;
	write(1, !result ? "[OK] " : "[KO] ", 5);
	putstr("test no solution\n");
	free(pattern);

	write(1, "\n", 1);
	printf("%d / %d tests passed\n", passed, total);
	return (0);
}
*/
