/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabouayy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 14:22:07 by yabouayy          #+#    #+#             */
/*   Updated: 2026/07/20 09:32:20 by yabouayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char	*tmp;

	tmp = dest;
	while (*src && dest < tmp + n)
		*dest++ = *src++;
	while (dest < tmp + n)
		*dest++ = '\0';
	return (tmp);
}
