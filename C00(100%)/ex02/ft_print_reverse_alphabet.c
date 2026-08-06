/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prin_reverse_alphabet.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabouayy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 14:46:43 by yabouayy          #+#    #+#             */
/*   Updated: 2026/07/15 15:03:11 by yabouayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	alph;

	alph = 'z';
	while (alph >= 'a')
	{
		write(1, &alph, 1);
		alph--;
	}
}
