/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahender <mahender@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 20:17:19 by mahender          #+#    #+#             */
/*   Updated: 2022/05/17 12:13:43 by mahender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		n;
	char	chr;

	n = (ft_strlen(s) + 1);
	chr = (char)c;
	while (n--)
	{
		if (s[n] == chr)
			return ((char *)&s[n]);
	}
	return (NULL);
}

/*int	main(void)
{
	int			c;
	const char	s[] = "Hola a todos los vecinos";
	c = '8';
	printf("%s", ft_strrchr(s, c));
	return (0);
}*/
