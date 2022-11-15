/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahender <mahender@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 17:42:48 by mahender          #+#    #+#             */
/*   Updated: 2022/04/22 18:42:10 by mahender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int a);
int	ft_isdigit(int a);

int	ft_isalnum(int a)
{
	return (ft_isalpha(a) || ft_isdigit(a));
}

/*int	main(void)
{
	int	a;

	a = ' ';
	printf("%d", ft_isalnum(a));
	return (0);
}*/
