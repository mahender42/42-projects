/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahender <mahender@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 19:16:45 by mahender          #+#    #+#             */
/*   Updated: 2022/05/16 19:30:12 by mahender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if ((c >= 97) && (c <= 122))
	{
		c -= 32;
		return (c);
	}
	else
		return (c);
}

/*int	main(void)
{
	int	c;

	c = 95;
	printf("%c", ft_toupper(c));
	return (0);
}*/
