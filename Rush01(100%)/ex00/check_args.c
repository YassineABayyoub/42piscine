/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymezian <aymezian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 17:56:12 by aymezian          #+#    #+#             */
/*   Updated: 2026/07/26 17:56:15 by aymezian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_arguments(int argc, char **argv)
{
	char	*str;
	int		i;

	if (argc != 2)
		return (0);
	str = argv[1];
	if (ft_strlen(str) != 31)
		return (0);
	i = 0;
	while (str[i])
	{
		if (i % 2 == 0 && (str[i] < '1' || str[i] > '4'))
			return (0);
		if (i % 2 == 1 && str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

/* TEST MAIN - COMMENTED OUT FOR PRODUCTION BUILD
#include <stdio.h>

typedef struct s_test
{
	const char		*desc;
	int				argc;
	char			*argv[3];
	int				expected;
} t_test;

int main(void)
{
	t_test tests[] = {
		{"valid input",
			2, {"./rush01", "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2", NULL}, 1},
		{"no argument at all",
			1, {"./rush01", NULL, NULL}, 0},
		{"too many arguments",
			3, {"./rush01", "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2", "extra"}, 0},
		{"only 4 tokens",
			2, {"./rush01", "4 3 2 1", NULL}, 0},
		{"17 tokens",
			2, {"./rush01", "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2 3", NULL}, 0},
		{"non-digit character",
			2, {"./rush01", "a 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2", NULL}, 0},
		{"digit 0 out of range",
			2, {"./rush01", "0 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2", NULL}, 0},
		{"digit 5 out of range",
			2, {"./rush01", "5 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2", NULL}, 0},
		{"glued digits (43)",
			2, {"./rush01", "43 2 1 1 2 2 2 4 3 2 1 1 2 2 2", NULL}, 0},
		{"leading space",
			2, {"./rush01", " 4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2", NULL}, 0},
		{"double space",
			2, {"./rush01", "4  3 2 1 1 2 2 2 4 3 2 1 1 2 2 2", NULL}, 0},
		{"trailing space",
			2, {"./rush01", "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2 ", NULL}, 0},
		{"empty string",
			2, {"./rush01", "", NULL}, 0},
		{"negative sign",
			2, {"./rush01", "-1 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2", NULL}, 0},
		{"wrong char at a space slot",
			2, {"./rush01", "4-3 2 1 1 2 2 2 4 3 2 1 1 2 2 2", NULL}, 0},
	};
	int	total;
	int	passed;
	int	result;
	int	ok;

	total = 15;
	passed = 0;
	while (i < total)
	{
		result = check_arguments(tests[i].argc, tests[i].argv);
		ok = (result == tests[i].expected);
		printf("[%s] test %2d: %-52s (expected %d, got %d)\n",
			ok ? "OK" : "KO", i + 1, tests[i].desc,
			tests[i].expected, result);
		if (ok)
			passed++;
		i++;
	}
	printf("\n%d / %d tests passed\n", passed, total);
	return (0);
}
*/
