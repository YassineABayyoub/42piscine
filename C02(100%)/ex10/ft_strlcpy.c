/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabouayy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 16:22:04 by yabouayy          #+#    #+#             */
/*   Updated: 2026/07/21 13:01:15 by yabouayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	lenght;

	lenght = 0;
	while (src[lenght])
		lenght++;
	if (size == 0)
		return (lenght);
	i = 0;
	while (*src && i < size - 1)
	{
		*dest++ = *src++;
		i++;
	}
	*dest = '\0';
	return (lenght);
}
