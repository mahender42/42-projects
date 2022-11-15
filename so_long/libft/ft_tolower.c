/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahender <mahender@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 19:32:27 by mahender          #+#    #+#             */
/*   Updated: 2022/05/16 19:29:24 by mahender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if ((c >= 65) && (c <= 90))
	{
		c += 32;
		return (c);
	}
	else
		return (c);
}

/*int	main(void)
{
	int	c;

	c = 'j';
	printf("%c", ft_tolower(c));
	return (0);
}*/
