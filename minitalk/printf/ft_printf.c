/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahender <mahender@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 19:03:31 by mahender          #+#    #+#             */
/*   Updated: 2022/09/23 12:38:36 by mahender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printer(va_list args, const char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ad_putchar_fd((va_arg(args, int)), 1);
	if (c == 's')
		len += ad_putstr(va_arg(args, char *));
	if (c == 'p')
		len += ft_printptr(va_arg(args, unsigned long long));
	if (c == 'd' || c == 'i')
		len += ad_putstr_fd(ft_itoa(va_arg(args, int)), 1);
	if (c == 'u')
		len += ad_putstr_fd(ft_uitoa(va_arg(args, unsigned int)), 1);
	if (c == 'x')
		len += ft_printhexa(va_arg(args, int), c);
	if (c == 'X')
		len += ft_printhexa(va_arg(args, int), c);
	if (c == '%')
		len += printper();
	return (len);
}

int	ft_printf(char const *s, ...)
{
	va_list	args;
	int		len;
	int		i;

	va_start (args, s);
	len = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			len += printer(args, s[i +1]);
			i++;
		}
		else
			len += ad_putchar_fd(s[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}
/*
int	main(void)
{
	char	c;
	char	*s;
	int	i;
	unsigned int	p;
	
	//c = 'A';
	//s = "Soy la string";
	//i = 0;
	p = -50;
	//ft_printf("Este es mi char: %c. \n", c);
	//ft_printf("%s.\n", s);
	printf("%d\n",ft_printf("--Este es mi hexa %X \n", p));
	printf("%d\n",printf("--Este es su hexa %X \n", p));
	//ft_printf("Este es mi num: %d.\n", i);
	return (0);
}
*/
