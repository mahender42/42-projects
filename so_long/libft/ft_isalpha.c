/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahender <mahender@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 18:26:16 by mahender          #+#    #+#             */
/*   Updated: 2022/04/22 18:12:47 by mahender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 65) && (c <= 90))
	{
		return (1);
	}
	if ((c >= 97) && (c <= 122))
	{
		return (1);
	}
	else
		return (0);
}

/*#include <stdio.h>

int	main(void)
{
	unsigned char	c;

	c = ' ';
	printf("%d", ft_isalpha(c));
}*/
