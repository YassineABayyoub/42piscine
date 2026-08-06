/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabouayy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 11:35:49 by yabouayy          #+#    #+#             */
/*   Updated: 2026/07/29 18:23:42 by yabouayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strstr(char *str, char *to_find)
{
	char	*start;
	char	*find;

	start = to_find;
	if (*to_find == '\0')
		return (str);
	while (*str)
	{
		find = str;
		to_find = start;
		while (*find && *to_find && *find == *to_find)
		{
			find++;
			to_find++;
		}
		if (*to_find == '\0')
			return (str);
		str++;
	}
	return ((char *)0);
}
