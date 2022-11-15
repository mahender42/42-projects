/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahender <mahender@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 20:44:59 by mahender          #+#    #+#             */
/*   Updated: 2022/05/16 15:45:25 by mahender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if ((c <= 126) && (c >= 32))
		return (1);
	return (0);
}

/*int	main(void)
{
	int	c;

	c = 127;
	printf("%d", ft_isprint(c));
	return (0);
}
*/
