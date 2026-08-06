/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabouayy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 16:18:06 by yabouayy          #+#    #+#             */
/*   Updated: 2026/07/21 13:00:46 by yabouayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	char	*start;
	char	*prev;

	prev = str - 1;
	start = str;
	if (*str >= 'a' && *str <= 'z')
		*str -= 32;
	str++;
	prev++;
	while (*str)
	{
		if (!((*(prev) >= 'A' && *(prev) <= 'Z')
				|| (*(prev) >= 'a' && *(prev) <= 'z')
				|| (*(prev) >= '0' && *(prev) <= '9')))
		{
			if (*str >= 'a' && *str <= 'z')
				*str -= 32;
		}
		else if (*str >= 'A' && *str <= 'Z')
			*str += 32;
		str++;
		prev++;
	}
	return (start);
}
