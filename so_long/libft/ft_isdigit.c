/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahender <mahender@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 19:58:45 by mahender          #+#    #+#             */
/*   Updated: 2022/04/22 18:27:40 by mahender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int nb)
{
	if ((nb >= 48) && (nb <= 57))
		return (1);
	else
		return (0);
}

/*int	main(void)
{
	unsigned char	nb;

	nb = '8';
	printf("%d", ft_isdigit(nb));
	return (0);
}*/
