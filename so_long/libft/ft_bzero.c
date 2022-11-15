/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahender <mahender@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 16:35:01 by mahender          #+#    #+#             */
/*   Updated: 2022/04/29 16:56:39 by mahender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n > 0)
	{
		*str = 0;
		str++;
		n--;
	}
}

/*int	main(void)
{
	char	s[] = "Hola hola hola";
	size_t	n;

	n = 6;
	ft_bzero(s, n);
	return (0);
}*/
