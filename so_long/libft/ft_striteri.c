/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahender <mahender@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 20:25:04 by mahender          #+#    #+#             */
/*   Updated: 2022/06/03 20:39:53 by mahender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	if (s && f)
	{
		while (s[i])
		{
			f(i, &s[i]);
			i++;
		}
	}
}

/*void	sumchar(unsigned int i, char c)
{
	char	chr;
	
	i = 1;
	chr = c + i;
	printf("Prueba: %c", chr);
}

int	main(void)
{
	char	st[10] = "hello 42!";
	ft_striteri(st, *sumchar);
	return (0);
}*/
