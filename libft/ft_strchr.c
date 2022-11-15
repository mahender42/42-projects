/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahender <mahender@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 19:41:36 by mahender          #+#    #+#             */
/*   Updated: 2022/05/17 12:13:05 by mahender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		n;
	int		i;
	char	chr;

	n = (ft_strlen(s) + 1);
	i = 0;
	chr = (char)c;
	while (i < n)
	{
		if (s[i] == chr)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
	int	c;
	const char	s[] = "Hola";
	
	c = 'a';
	printf("%s", ft_strchr(s, c));
	return (0);
}*/
