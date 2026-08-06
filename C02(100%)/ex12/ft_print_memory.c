/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabouayy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 12:05:00 by yabouayy          #+#    #+#             */
/*   Updated: 2026/08/06 12:08:11 by yabouayy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		write(1, &c, 1);
		i++;
	}
}

void	ft_xdigit(unsigned long long nb, int check)
{
	char	*xdigit;

	xdigit = "0123456789abcdef";
	if (nb < 16 && check == 1)
		ft_putchar('0', 1);
	if (nb >= 16)
	{
		ft_xdigit(nb / 16, 0);
		ft_xdigit(nb % 16, 0);
	}
	else
		ft_putchar(xdigit[nb], 1);
}

void	ft_print_addr(unsigned long long addr)
{
	unsigned long long	tmp;
	int					i;

	tmp = addr;
	i = 1;
	while (i++ < 15)
	{
		if (tmp < 16)
			ft_putchar('0', 1);
		tmp /= 16;
	}
	ft_xdigit(addr, 0);
}

void	ft_print_data(unsigned char *c, int size)
{
	int		i;

	i = -1;
	while (i++ < 16)
	{
		if (i % 2 == 0)
			ft_putchar(' ', 1);
		if (i < size)
		{
			ft_xdigit((unsigned long long)*(c + i), 1);
		}
		else if (i != 16)
			ft_putchar(' ', 2);
	}
	i = -1;
	while (i++ < size - 1)
	{
		if (*(c + i) <= 31 || *(c + i) >= 127)
			ft_putchar('.', 1);
		else
			ft_putchar(*(c + i), 1);
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned int	columns;

	i = 0;
	while (i * 16 < size)
	{
		if (i < size / 16)
			columns = 16;
		else
			columns = size % 16;
		ft_print_addr((unsigned long long)addr + (i * 16));
		ft_putchar(':', 1);
		ft_print_data(addr + (i * 16), columns);
		ft_putchar('\n', 1);
		i++;
	}
	return (addr);
}
/* 
int main()
{
	char *str = "Hello W\1rld! This is a t\2st to print th\1 memory addr\2ss";
	int	size = 0;

	while (str[size])
		size++;
	ft_print_memory(str, size);
}*/
