/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabouayy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 16:23:59 by yabouayy          #+#    #+#             */
/*   Updated: 2026/08/01 16:27:27 by yabouayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_sep(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	word_count(char *str, char *charset)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (!is_sep(*str, charset) && !in_word)
		{
			count++;
			in_word = 1;
		}
		else if (is_sep(*str, charset))
			in_word = 0;
		str++;
	}
	return (count);
}

int	word_len(char *str, char *charset)
{
	int	len;

	len = 0;
	while (str[len] && !is_sep(str[len], charset))
		len++;
	return (len);
}

char	*copy_word(char *str, char *charset)
{
	char	*word;
	int		len;
	int		i;

	len = word_len(str, charset);
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		words;
	int		i;

	words = word_count(str, charset);
	tab = (char **)malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (*str)
	{
		while (*str && is_sep(*str, charset))
			str++;
		if (*str)
		{
			tab[i++] = copy_word(str, charset);
			while (*str && !is_sep(*str, charset))
				str++;
		}
	}
	tab[i] = NULL;
	return (tab);
}
