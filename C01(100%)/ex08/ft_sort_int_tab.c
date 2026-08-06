/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabouayy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 21:01:20 by yabouayy          #+#    #+#             */
/*   Updated: 2026/07/18 12:53:49 by yabouayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	*i;
	int	*last;
	int	temp;
	int	*min;

	last = tab + size -1;
	while (tab < last)
	{
		i = tab;
		min = tab;
		while (i <= last)
		{
			if (*min > *i)
				min = i;
			i++;
		}
		temp = *min;
		*min = *tab;
		*tab = temp;
		tab++;
	}
}
