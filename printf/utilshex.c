/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilshex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahender <mahender@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:30:10 by mahender          #+#    #+#             */
/*   Updated: 2022/09/23 12:40:12 by mahender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hexa_len(unsigned long ptr)
{
	int	index;

	index = 0;
	while (ptr != 0)
	{
		index++;
		ptr = ptr / 16;
	}
	return (index);
}

void	putptr(unsigned long ptr)
{
	int	len;

	len = 0;
	if (ptr >= 16)
	{
		putptr(ptr / 16);
		putptr(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			len += ad_putchar_fd((ptr + '0'), 1);
		else
			len += ad_putchar_fd((ptr - 10 + 'a'), 1);
	}
}

int	ft_printptr(unsigned long long ptr)
{
	int	i;

	i = 0;
	i += write(1, "0x", 2);
	if (ptr == 0)
		i += write(1, "0", 1);
	else
	{
		putptr(ptr);
		i += hexa_len(ptr);
	}
	return (i);
}

void	puthexa(unsigned int hexa, const char x)
{
	int	len;

	len = 0;
	if (hexa >= 16)
	{
		puthexa(hexa / 16, x);
		puthexa(hexa % 16, x);
	}
	else
	{
		if (hexa <= 9)
			len += ad_putchar_fd((hexa + '0'), 1);
		else
		{
			if (x == 'x')
				len += ad_putchar_fd((hexa - 10 + 'a'), 1);
			else
				len += ad_putchar_fd((hexa - 10 + 'A'), 1);
		}
	}
}

int	ft_printhexa(unsigned int hexa, const char x)
{
	int	i;

	i = 0;
	if (hexa == 0)
		i += write(1, "0", 1);
	else
	{
		puthexa(hexa, x);
		i += hexa_len(hexa);
	}
	return (i);
}
